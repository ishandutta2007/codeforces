//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "E"

typedef long long ll;
typedef long double ld;

struct item{
    ll suml,sumr,sumb;
    int minv,maxv;     
    int size;
    item(int x){
        suml = sumr = sumb = 0;
        minv = maxv = x;
        size = 1;
    }
    void dbg(){
        eprintf("suml = "LLD", sumr = "LLD", sumb = "LLD"\n",suml,sumr,sumb);
        eprintf("minv = %d, maxv = %d, size = %d\n",minv,maxv,size);

    }
};

item merge(item l,item r){
    //eprintf("!!!!!!!!!!!!!!!!!\n");
    assert(l.maxv < r.minv);
    item res = l;
    res.maxv = r.maxv;
    res.size += r.size;
    res.suml += r.suml + r.size * 1LL * (r.minv - l.minv);
    res.sumr += r.sumr + l.size * 1LL * (r.maxv - l.maxv);
    res.sumb += r.sumb + r.size * 1LL * l.size * (r.minv - l.maxv) + r.suml * 1LL * l.size + r.size * 1LL * l.sumr;
    /*l.dbg();
    r.dbg();
    eprintf("===========");
    res.dbg();
    eprintf("\n\n");*/
    return res;
}

struct node{
    node *l,*r;
    int x,y; 
    item val;
    node(int x):x(x),val(x){
        l = r = 0;             
        y = rand();
    }
};

void update(node* v){    
    v->val = item(v->x);
    if (v->l)
        v->val = merge(v->l->val, v->val);
    if (v->r)
        v->val = merge(v->val,v->r->val);
}

node* merge(node* l,node* r){
    if (!l) return r;
    if (!r) return l;
    if (l->y < r->y){
        l->r = merge(l->r,r);
        update(l);
        return l;
    }
    r->l = merge(l,r->l);
    update(r);
    return r;
}

void split(node* v,int x,node* &l,node* &r){
    if (!v) {l = r = 0; return;};
    //eprintf("!!! %d %d\n",v->x,x);                                       
    if (v->x >= x){
        r = v;
        split(r->l,x,l,r->l);
        update(r);
        return;
    }              
    //eprintf("???\n");
    l = v;
    split(l->r,x,l->r,r);
    update(l);
    return;
}

node* root;

void print(node* v,int deep = 0){
    if (!v) return;
    print(v->l,deep + 2);
//  for (int i = 0; i < deep; i++)
//      eprintf(" ");
    eprintf("%d ",v->x);
    print(v->r,deep + 2);
}

void erase(int val){         
    node *l,*m,*r;
    split(root,val,l,r);
    split(r,val+1,m,r);
    root = merge(l,r);
}

void insert(int val){
    node *l,*m,*r;
    split(root,val,l,r);
    m = new node(val);;
    root = merge(l,merge(m,r));

}
           

int a[110000];
int b[110000];
int n,m;

node* build(int l,int r){
    if (l == r) return 0;
    if (l == r-1) return new node(a[l]);
    return merge(build(l,(l+r)/2),build((l+r)/2,r));
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]),b[i] = a[i];

    sort(a,a+n);    

    root = build(0,n);
    //print(root);
    //eprintf("\n\n");

    scanf("%d",&m);

    for (int i = 0; i < m; i++){
        int ty;
        scanf("%d",&ty); 
        if (ty == 1){
            int p,d;
            scanf("%d %d",&p,&d);
            --p;
            erase(b[p]);
            b[p] += d;
            insert(b[p]);
        }
        else {
            int lf,rg;
            scanf("%d %d",&lf,&rg);
            node *l,*m,*r;
            split(root,lf,l,r);
            split(r,rg+1,m,r);
            if (!m) printf("0\n");
            else printf(LLD"\n",m->val.sumb);
            root = merge(l,merge(m,r));                 
        }
        //print(root);
        //eprintf("\n");    
    }
      
    TIMESTAMP(end);
    return 0;
}