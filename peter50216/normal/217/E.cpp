// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}
/* Size Balanced Tree
 * (1) size[right[node]]>=size[left[left[node]]], size[right[left[node]]]
 * (2) size[left[node]]>=size[left[right[node]]], size[right[right[node]]]
 */
namespace SBT{
    typedef int v_type;
    // something that is LARGER than every value possible
    const v_type INF = 1000000000;
    struct node{
        v_type val; // value of the node
        int sz; // size of the subtree
        node *l,*r;
        node(int v, int s=1); // argument s for null node
    };
    node _null_nd(INF,0);
    node *null_nd=&_null_nd;
    node::node(v_type v, int s){val=v;sz=s;l=&_null_nd;r=&_null_nd;}
    // assume nd != null_nd
    inline void calc_size(node *nd){
        nd->sz=nd->l->sz+nd->r->sz+1;
    }
    // assume nd->l != null_nd, return new root
    node* right_rotate(node *nd){
        node *k=nd->l; nd->l=k->r; k->r=nd;
        k->sz=nd->sz;
        calc_size(nd);
        return k;
    }
    // assume node->r != null_node, return new root
    node* left_rotate(node *nd){
        node *k=nd->r; nd->r=k->l; k->l=nd;
        k->sz=nd->sz;
        calc_size(nd);
        return k;
    }
    // Core function, run in amortized O(1)
    // f==true -> check (1), otherwise check (2)
    // return new root
    node* maintain(node *nd, bool f){
        if(nd==null_nd) return nd;
        if(!f){
            if(nd->l->l->sz > nd->r->sz){
                nd=right_rotate(nd);
            }else if(nd->l->r->sz > nd->r->sz){
                nd->l=left_rotate(nd->l);
                nd=right_rotate(nd);
            }else return nd;
        }else{
            if(nd->r->r->sz > nd->l->sz){
                nd=left_rotate(nd);
            }else if(nd->r->l->sz > nd->l->sz){
                nd->r=right_rotate(nd->r);
                nd=right_rotate(nd);
            }else return nd;
        }
        nd->l=maintain(nd->l, false);
        nd->r=maintain(nd->r, true);
        nd=maintain(nd, false);
        nd=maintain(nd, true);
    }
    // insert v into SBT, return new root
    node* insert(node* nd, v_type v){
        if(nd==null_nd){
            return new node(v);
        }else{
            nd->sz++;
            if(v<nd->val){
                nd->l=insert(nd->l,v);
            }else{
                nd->r=insert(nd->r,v);
            }
            return maintain(nd, v>=nd->val);
        }
    }
    // store the deleted value
    v_type deleted;
    // delete THE LAST SEARCHED ELEMENT, return new root
    // CAUTION: value of a node could be changed
    //          so don't save node* outside (except root)
    //          if using delete.
    node* del(node* nd, v_type v){
        nd->sz--;
                         // the value is not in SBT
        if(v==nd->val || (v<nd->val&&nd->l==null_nd)
                      || (v>nd->val&&nd->r==null_nd)){
            deleted=nd->val;
            if(nd->l==null_nd){
                node *k=nd->r;
                //delete nd;
                nd=k;
            }else if(nd->r==null_nd){
                node *k=nd->l;
                //delete nd;
                nd=k;
            }else{
                nd->l=del(nd->l,INF);
                nd->val=deleted;
            }
        }else{
            if(v<nd->val){
                nd->l=del(nd->l,v);
            }else{
                nd->r=del(nd->r,v);
            }
        }
        return nd;
    }
    // find if a value is in SBT, return null_nd if not found
    node* find(node* nd, v_type v){
        if(nd==null_nd) return null_nd;
        if(nd->val==v) return nd;
        else if(v < nd->val) return find(nd->l,v);
        else return find(nd->r,v);
    }
    // find the k-th small node, (1 <= k <= nd->size)
    node* rank(node* nd, int k){
        if(k==nd->l->sz+1) return nd;
        else if(k<=nd->l->sz) return rank(nd->l,k);
        else return rank(nd->r,k-nd->l->sz-1);
    }
    // build the tree with a SORTED array, MUCH faster than insert one by one.
    // return new root
    node* build(v_type* arr, int l, int r){
        int m=(l+r)/2;
        SBT::node* nd=new SBT::node(arr[m]);
        nd->sz=r-l+1;
        if(l<m)nd->l=build(arr,l,m-1);
        if(r>m)nd->r=build(arr,m+1,r);
        return nd;
    }
}
const int MAXN=3000100;
char in[MAXN];
int pre[3000100];
int ll[5010],rr[5010];
char out[MAXN];
inline char run(int np){
    if(out[np])return out[np];
    return out[np]=run(pre[np]);
}
inline void traverse(SBT::node* nd,int r){
    if(nd->l!=SBT::null_nd)traverse(nd->l,r);
    out[nd->val]=in[nd->l->sz+r];
    if(nd->r!=SBT::null_nd)traverse(nd->r,nd->l->sz+1+r);
}
int id[3000100];
int main(){
    int k,q,i,j;
    scanf("%s%d%d",in,&k,&q);
    for(i=0;i<k;i++)id[i]=i+1;
    SBT::node *root=SBT::build(id,0,k-1);
    for(i=0;i<q;i++){
        scanf("%d%d",&ll[i],&rr[i]);
    }
    for(i=q-1;i>=0;i--){
        int n=root->sz;
        int l=ll[i],r=rr[i];
        if(r>=n)continue;
        int len=r-l+1;
        int r2=r+len;
        if(r2>n)r2=n;
        int id=0;
        for(j=1;j<=r2-r;j++){
            SBT::node* nd=SBT::rank(root,r+1);
            id+=2;
            if(id>len)id=1;
            SBT::node* pn=SBT::rank(root,l+id-1);
            pre[nd->val]=pn->val;
            root=SBT::del(root,nd->val);
        }
    }
    traverse(root,0);
    for(i=1;i<=k;i++)putchar(run(i));
    puts("");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

//2070617  217E  Alien DNA  Accepted  GNU C++  1730 ms  Aug 31, 2012 8:27:36 AM