// @author peter50216
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
#include<iostream>
#include<sstream>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y);
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z);
#define RS(x) scanf("%s",x);
#define PI(x) printf("%d\n",x);
#define PIS(x) printf("%d ",x);
#define CASET int ___T,cas=1;scanf("%d",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#else
#define FILEIO(x) ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

vector<int> ed[101000];
vector<int> que[101000];
int ans[101000];
int iid[101000],oid[101000];
int id;
struct node{
    int cnt,cov;
    node *l,*r;
    node(){
        l=r=NULL;
        cnt=0;
        cov=0;
    }
    node(const node* x){
        cnt=x->cnt;
        cov=x->cov;
        l=x->l;r=x->r;
    }
};
node *r[101000];
inline void dfs(int np,int p){
    iid[np]=id++;
    FOR(it,ed[np]){
        int y=*it;
        if(y==p)continue;
        dfs(y,np);
    }
    oid[np]=id++;
}
inline node* build(int x,int y){
    node* r=new node();
    if(x<y){
        int m=(x+y)/2;
        r->l=build(x,m);
        r->r=build(m+1,y);
    }
    return r;
}
inline node* cov(node* n,int l,int r,int x,int y){
    node *ret=new node(n);
    if(l==x&&r==y){
        ret->cov=1;
        ret->cnt=r-l+1;
        return ret;
    }
    if(ret->cov)return ret;
    int m=(l+r)/2;
    if(y<=m){
        ret->l=cov(ret->l,l,m,x,y);
    }else if(x>m){
        ret->r=cov(ret->r,m+1,r,x,y);
    }else{
        ret->l=cov(ret->l,l,m,x,m);
        ret->r=cov(ret->r,m+1,r,m+1,y);
    }
    ret->cnt=ret->l->cnt+ret->r->cnt;
    return ret;
}
inline void dfs2(int np,int p){
    node *c=r[p];
    FOR(it,que[np]){
        int y=*it;
        c=cov(c,0,id-1,iid[np],oid[np]);
        c=cov(c,0,id-1,iid[y],oid[y]);
    }
    r[np]=c;
    ans[np]=c->cnt/2;
    if(ans[np])ans[np]--;
    FOR(it,ed[np]){
        int y=*it;
        if(y==p)continue;
        dfs2(y,np);
    }
}
int main(){
    DRII(n,m);
    REP(i,n-1){
        DRII(a,b);
        a--;b--;
        ed[a].PB(b);
        ed[b].PB(a);
    }
    REP(i,m){
        DRII(a,b);
        a--;b--;
        que[a].PB(b);
        que[b].PB(a);
    }
    id=0;
    dfs(0,n);
    r[n]=build(0,id-1);
    dfs2(0,n);
    REP(i,n)printf("%d%c",ans[i],SEP(i==n-1));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread