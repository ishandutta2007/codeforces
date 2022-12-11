#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF =1e8;
const int maxn=600010;
namespace BIT{
    int data[maxn];
    int n;
    void init(int _n){
        memset(data,0,sizeof(data));
        n=_n;
    }
    int lowbit(int x){
        return x&(-x);
    }
    void add(int pos,int val){
        while(pos<=n){
            data[pos]+=val;
            pos+=lowbit(pos);
        }
    }
    int sum(int pos){
        int ret=0;
        while(pos){
            ret+=data[pos];
            pos-=lowbit(pos);
        }
        return ret;
    }

}

namespace link_cut_tree{
    #define NIL POOL
    const int max_n =630010;
    struct Node{
        int val,pos,mpos;
        int l,r;
        bool rev,root;
        Node *lch,*rch,*fa;
        Node (){
            root=rev=false;
            mpos=pos=0;
        }
        Node (int _val,int _pos,Node *_lch,Node *_rch,Node *_fa)
        :val(_val),pos(_pos),lch(_lch),rch(_rch),fa(_fa){
            root=true;
            mpos=pos;
            rev=false;
        }
    }POOL[maxn],*pool[maxn];
    struct LCT{
        Node *node[max_n],*stk[maxn];
        LCT(){}
        int tot;
        int tp;
        int min1(int a,int b){
            if(node[a]->val<node[b]->val)return a;
            return b;
        }
        void init(){
            tot=0;
            for(int i=1;i<maxn;i++)pool[tot++]=POOL+i;
            new(NIL)Node;
            NIL->lch=NIL->rch=NIL->fa=NIL;
            node[0]=new(pool[--tot])Node(INF,0,NIL,NIL,NIL);
        }
        void build(int n){
            tp=n;
            for(int i=1;i<=n;i++){
                node[i]=new(pool[--tot])Node(0,0,NIL,NIL,NIL);
            }
        }
        void update(Node *t){
            if(t==NIL)return;
            t->mpos=min1(t->pos,min1(t->lch->mpos,t->rch->mpos));
        }
        void reverse(Node *t){
            if(t==NIL)return;
            t->rev^=1;
            swap(t->lch,t->rch);
        }
        void pushdown(Node *t){
            if(t==NIL)return;
            if(t->rev){
                reverse(t->lch);
                reverse(t->rch);
                t->rev^=1;
            }
        }
        void zig(Node *t){
            Node *f=t->fa,*c=t->rch;
            if(f->root)t->root=true,f->root=false;
            else (f->fa->lch==f?f->fa->lch:f->fa->rch)=t;
            t->fa=f->fa,t->rch=f,f->lch=c,f->fa=t,c->fa=f;
            update(f);
        }
        void zag(Node *t){
            Node *f=t->fa,*c=t->lch;
            if(f->root)t->root=true,f->root=false;
            else (f->fa->lch==f?f->fa->lch:f->fa->rch)=t;
            t->fa=f->fa,t->lch=f,f->rch=c,f->fa=t,c->fa=f;
            update(f);
        }
        void splay(Node *t){
            Node *p=t;
            int top=0;
            stk[top]=t;
            while(!p->root){
                stk[++top]=p->fa;
                p=p->fa;
            }
            while(top>=0){
                pushdown(stk[top--]);
            }
            while(!t->root){
                if(t->fa->root){
                    if(t->fa->lch==t)zig(t);
                    else zag(t);
                }
                else {
                    if(t->fa->fa->lch==t->fa){
                        if(t->fa->lch==t)zig(t->fa),zig(t);
                        else zag(t),zig(t);
                    }
                    else {
                        if(t->fa->lch==t)zig(t),zag(t);
                        else zag(t->fa),zag(t);
                    }
                }
            }
            update(t);
        }
        Node * expose(Node *t){
            Node *p=t,*q=NIL;
            while(p!=NIL){
                splay(p);
                p->rch->root=true;
                p->rch=q;
                p->rch->root=false;
                update(p);
                q=p;
                p=p->fa;
            }
            return q;
        }
        void evert(Node *t){
            t=expose(t);
            reverse(t);
        }
        void cut(int a,int b){
            evert(node[b]);
            expose(node[a]);
            splay(node[a]);
            node[a]->lch->fa=NIL;
            node[a]->lch->root=true;
            node[a]->lch=NIL;
            expose(node[b]);
        }
        void link(int a,int b){
            evert(node[b]);
            splay(node[b]);
            node[b]->fa=node[a];
            expose(node[b]);
        }
        void Link(int a,int b,int val){
            node[++tp]=new(pool[--tot])Node(val,tp,NIL,NIL,NIL);
            node[tp]->l=a;
            node[tp]->r=b;
            link(a,tp);
            link(tp,b);
            BIT::add(val,1);
        }
        int querry(int a,int b){
            if(getroot(node[b])!=getroot(node[a]))return -1;
            Node *p=node[b],*q=NIL;
            expose(node[a]);
            int ret;
            while(p!=NIL){
                splay(p);
                if(p->fa==NIL){
                    ret=min1(p->pos,min1(p->rch->mpos,q->mpos));
                }
                p->rch->root=true;
                p->rch=q;
                p->rch->root=false;
                update(p);
                q=p;
                p=p->fa;
            }
            return ret;
        }
        void erase(int a){
            BIT::add(node[a]->val,-1);
            cut(node[a]->l,a);
            cut(node[a]->r,a);
            pool[tot++]=node[a];
        }
        Node* getroot(Node *t){
            t=expose(t);
            while(1){
                if(t->lch!=NIL) t=t->lch;
                else return t;
            }
        }

    };
}
link_cut_tree::LCT T;

struct Querry{
    int kind,ans,l,r,id;
    Querry(){}
    Querry(int _k,int _l,int _r,int _id)
    :kind(_k),l(_l),r(_r),id(_id){
        if(l>r)swap(l,r);
    }
    bool operator<(const Querry  & a)const{
        if(r==a.r){
            if(kind==a.kind){
                return l<a.l;
            }
            return kind<a.kind;
        }
        return r<a.r;
    }
}Q[maxn];
bool cmp(const Querry & a,const Querry & b){
    if(a.kind==b.kind)return a.id<b.id;
    return a.kind>b.kind;
}
void read(int &a){
    char c;
    while(c=getchar(),c<'0'||c>'9');
    a=c-'0';
    while(c=getchar(),c>='0'&&c<='9')
        a=a*10+c-'0';
}
int ttt;
int main(){
	int n,m,q;
    scanf("%d%d",&n,&ttt);
    scanf("%d",&m);
    T.init();
    T.build(n);
    BIT::init(n);
    int a,b,tot=0;
    for(int i=0;i<m;i++){
            read(a),read(b);
//            scanf("%d%d",&a,&b);
        Q[tot++]=Querry(0,a,b,i);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
            read(a),read(b);
//            scanf("%d%d",&a,&b);
        Q[tot++]=Querry(1,a,b,i);
    }
    sort(Q,Q+tot);
    for(int i=0;i<tot;i++){
        if(Q[i].kind==0){
            int tp=T.querry(Q[i].l,Q[i].r);
            if(tp==-1){
                T.Link(Q[i].r,Q[i].l,Q[i].l);
                continue;
            }
            if(T.node[tp]->val>=Q[i].l)continue;
            T.erase(tp);
            T.Link(Q[i].r,Q[i].l,Q[i].l);
        }
        else {
            Q[i].ans=BIT::sum(Q[i].r)-BIT::sum(Q[i].l-1);
        }
    }
    sort(Q,Q+tot,cmp);
    for(int i=0;i<q;i++){
        printf("%d\n",Q[i].r-Q[i].l+1-Q[i].ans);
    }
    return 0;

}