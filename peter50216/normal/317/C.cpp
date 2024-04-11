// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
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
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
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
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

int n,v,e;
int ai[310],bi[310];
vector<pair<PII,int> > ans;
int vis[310];
vector<int> ed[310];
LL s1,s2;
int nei[310][310];
int mid[310][310];
int dd[310][310];
int ps[310],pc;
inline void dfs(int np){
    if(vis[np])return;
    vis[np]=1;
    ps[pc++]=np;
    s1+=ai[np];
    s2+=bi[np];
    REP(i,SZ(ed[np])){
        dfs(ed[np][i]);
    }
}
inline void mak(int x,int y,int c){//make ai[x] to c
    if(ai[x]==c)return;
    if(ai[x]>c){
        ans.PB(MP(MP(x,y),ai[x]-c));
        ai[y]+=ai[x]-c;
        ai[x]=c;
    }else if(ai[x]<c){
        ans.PB(MP(MP(y,x),c-ai[x]));
        ai[y]-=c-ai[x];
        ai[x]=c;
    }
}
vector<int> ro;
int reserve[310];
const int INF=1000000000;
inline void findr(int a,int b){
    if(nei[a][b]){
        ro.PB(a);
        return;
    }
    findr(a,mid[a][b]);
    findr(mid[a][b],b);
}
int main(){
    RIII(n,v,e);
    REP(i,n)RI(ai[i]);
    REP(i,n)RI(bi[i]);
    REP(i,n)REP(j,n)dd[i][j]=(i==j?0:INF);
    REP(i,n)REP(j,n)mid[i][j]=(i==j?i:-1);
    while(e--){
        DRII(a,b);
        a--;b--;
        ed[a].PB(b);ed[b].PB(a);
        nei[a][b]=nei[b][a]=1;
        dd[a][b]=dd[b][a]=1;
    }
    REP(k,n)REP(i,n)REP(j,n)if(dd[i][j]>dd[i][k]+dd[k][j]){
        dd[i][j]=dd[i][k]+dd[k][j];
        mid[i][j]=k;
    }
    REP(v,n)if(!vis[v]){
        s1=0;s2=0;
        pc=0;
        dfs(v);
        if(s1!=s2){
            puts("NO");
            return 0;
        }
        while(1){
            int a1=-1,a2=-1;
            REP(i,pc){
                if(ai[ps[i]]>bi[ps[i]]){
                    a1=ps[i];
                }else if(ai[ps[i]]<bi[ps[i]]){
                    a2=ps[i];
                }
            }
            if(a1==-1)break;
            //printf("a1=%d a2=%d\n",a1,a2);
            ro.clear();
            findr(a1,a2);
            ro.PB(a2);
            int nm=min(ai[a1]-bi[a1],bi[a2]-ai[a2]);
            REP(i,SZ(ro)){
                if(ai[ro[i]]>nm){
                    reserve[ro[i]]=ai[ro[i]]-nm;
                }else reserve[ro[i]]=0;
            }
            reserve[a1]=ai[a1]-nm;
            reserve[a2]=ai[a2];
            for(int i=0;i<SZ(ro)-1;i++){
                int x=ro[i],y=ro[i+1];
                int v1=ai[x]-reserve[x],v2=ai[y]-reserve[y];
                mak(x,y,reserve[x]+v2);
            }
            for(int i=SZ(ro)-2;i>0;i--){
                int x=ro[i],y=ro[i-1];
                int v1=ai[x]-reserve[x],v2=ai[y]-reserve[y];
                mak(x,y,reserve[x]+v2);
            }
            //REP(i,n)printf("#%d %d->%d reserve=%d\n",i,ai[i],bi[i],reserve[i]);
        }
    }
    PI(SZ(ans));
    REP(i,SZ(ans))printf("%d %d %d\n",ans[i].F.F+1,ans[i].F.S+1,ans[i].S);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread