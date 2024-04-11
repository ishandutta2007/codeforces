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
const int INF=314000000;
inline int add(int a,int b){
    return min(INF,a+b);
}
inline int mul(int a,int b){
    return min((LL)INF,a*(LL)b);
}
typedef map<int,int> MII;
vector<MII> ps[101000];
set<int> to[101000];
vector<int> ed[101000];
vector<int> re[101000];
int vis[101000],visid;
int allp[101000],ac;
int cnt;
vector<int> sccps[101000];
int sccid[101000];
int sccpc[101000],sccc;
int sccinf[101000];
bool cane[101000];
inline void dfs(int np){
    vis[np]=visid;
    REP(i,SZ(ed[np])){
        int y=ed[np][i];
        if(vis[y]==visid||!cane[y])continue;
        dfs(y);
    }
    allp[ac++]=np;
}
inline void dfs2(int np,int sc){
    sccid[np]=sc;
    sccps[sc].PB(np);
    cnt++;
    REP(i,SZ(re[np])){
        int y=re[np][i];
        if(sccid[y]!=-1||!cane[y])continue;
        dfs2(y,sc);
    }
}
vector<PII> revs[101000];
int ans1[101000],ans2[101000];
vector<int> used[101000];
inline void dfs3(int np){
    vis[np]=visid;
    REP(i,SZ(sccps[np]))REP(j,SZ(re[sccps[np][i]])){
        int y=sccid[re[sccps[np][i]][j]];
        if(vis[y]==visid)continue;
        dfs3(y);
    }
}
inline int f2(int np){
    if(ans2[np]!=-1)return ans2[np];
    ans2[np]=0;
    REP(i,SZ(ps[np])){
        int a=ps[np][i][-1];
        bool f=1;
        FOR(it,ps[np][i]){
            if(it->F==-1)continue;
            if(!cane[it->F]){
                f=0;break;
            }
            a=add(a,mul(it->S,f2(it->F)));
        }
        if(f)ans2[np]=max(ans2[np],a);
    }
    return ans2[np];
}
vector<int> curc[101000];
int main(){
    DRII(m,n);
    REP(i,m){
        DRI(a);
        a--;
        DRI(k);
        MII x;
        while(k--){
            DRI(c);
            if(c!=-1)c--;
            x[c]++;
        }
        ps[a].PB(x);
    }
    queue<int> caneq;
    REP(i,n){
        REP(j,SZ(ps[i])){
            FOR(it,ps[i][j])if(it->F!=-1)revs[it->F].PB(MP(i,j));
            if(SZ(ps[i][j])==1)cane[i]=1;
        }
        if(cane[i])caneq.push(i);
        used[i].resize(SZ(ps[i]));
    }
    while(!caneq.empty()){
        int np=caneq.front();caneq.pop();
        REP(i,SZ(revs[np])){
            int y=revs[np][i].F,j=revs[np][i].S;
            if(cane[y])continue;
            used[y][j]++;
            if(used[y][j]==SZ(ps[y][j])-1){
                cane[y]=1;
                caneq.push(y);
            }
        }
    }
    REP(i,n){
        REP(j,SZ(ps[i])){
            bool f=1;
            FOR(it,ps[i][j])if(it->F!=-1&&!cane[it->F]){
                f=0;break;
            }
            if(f){
                FOR(it,ps[i][j])if(it->F!=-1){
                    to[i].insert(it->F);
                }
            }
        }
    }
    REP(i,n)FOR(it,to[i]){
        ed[i].PB(*it);
        re[*it].PB(i);
    }
    ac=0;
    visid++;
    REP(i,n)if(cane[i]&&vis[i]!=visid)dfs(i);
    MS1(sccid);
    PER(ii,ac){
        int i=allp[ii];
        if(sccid[i]!=-1)continue;
        cnt=0;
        dfs2(i,sccc);
        sccpc[sccc]=cnt;
        sccc++;
    }
    visid++;
    REP(i,sccc){
        if(vis[i]==visid)continue;
        bool f=0;
        if(sccpc[i]>1)f=1;
        else{
            int ii=sccps[i][0];
            //printf("# ii=%d\n",ii);
            REP(j,SZ(ps[ii])){
                FOR(it,ps[ii][j]){
                    //printf("j=%d %d %d\n",j,it->F,it->S);
                    if(it->F==ii)f=1;
                    else if(it->F!=-1&&!cane[it->F]){
                        f=0;break;
                    }
                }
              //  printf("   j=%d %d\n",j,(int)f);
                if(f)break;
            }
        }
        if(f)dfs3(i);
    }
    REP(i,sccc)if(vis[i]==visid)sccinf[i]=1;
    MS1(ans1);
    MS1(ans2);
    REP(i,n){
        if(cane[i]){
            if(sccinf[sccid[i]])ans2[i]=-2;
            else ans2[i]=f2(i);
        }
    }
    priority_queue<PII> pq;
    REP(i,n){
        if(!cane[i])continue;
        ans1[i]=INF;
        REP(j,SZ(ps[i])){
            if(SZ(ps[i][j])==1)ans1[i]=min(ans1[i],ps[i][j][-1]);
        }
        if(ans1[i]!=INF)pq.push(MP(-ans1[i],i));
    }
    REP(i,n){
        used[i].clear();
        used[i].resize(SZ(ps[i]));
        curc[i].resize(SZ(ps[i]));
    }
    while(!pq.empty()){
        PII p=pq.top();pq.pop();
        if(p.F!=-ans1[p.S])continue;
        int np=p.S;
        REP(i,SZ(revs[np])){
            int y=revs[np][i].F,j=revs[np][i].S;
            if(!cane[y])continue;
            used[y][j]++;
            curc[y][j]=add(curc[y][j],mul(ps[y][j][np],ans1[np]));
            if(used[y][j]==SZ(ps[y][j])-1){
                if(ans1[y]>curc[y][j]+ps[y][j][-1]){
                    ans1[y]=curc[y][j]+ps[y][j][-1];
                    pq.push(MP(-ans1[y],y));
                }
            }
        }
    }
    REP(i,n)printf("%d %d\n",ans1[i],ans2[i]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread