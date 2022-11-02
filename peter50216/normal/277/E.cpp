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

int xi[410],yi[410];
int f[810][810];
double co[810][810];
vector<int> ed[810];
inline void adde(int x,int y,int ca,double cost){
    f[x][y]=ca;
    f[y][x]=0;
    co[x][y]=cost;
    co[y][x]=-cost;
    ed[x].PB(y);
    ed[y].PB(x);
}
inline double sq(double x){return x*x;}
inline double dist(int i,int j){
    return sqrt(sq(xi[i]-xi[j])+sq(yi[i]-yi[j]));
}
int que[810],qs,qe;
bool inq[810];
inline void push(int a){
    if(inq[a])return;
    inq[a]=1;
    que[qe++]=a;
    if(qe==810)qe=0;
}
inline int pop(){
    int a=que[qs++];
    if(qs==810)qs=0;
    inq[a]=0;
    return a;
}
double dis[810];
int pre[810];
const double INF=1e100;
inline bool spfa(int n,double& cost){
    qs=qe=0;
    REP(i,n){
        dis[i]=INF;
        inq[i]=0;
    }
    dis[0]=0;
    push(0);
    while(qs!=qe){
        int np=pop();
        REP(i,SZ(ed[np])){
            int y=ed[np][i];
            if(f[np][y]==0)continue;
            if(dis[y]>dis[np]+co[np][y]){
                dis[y]=dis[np]+co[np][y];
                pre[y]=np;
                push(y);
            }
        }
    }
    if(dis[n-1]==INF)return 0;
    cost=dis[n-1];
    int np=n-1;
    while(np){
        f[pre[np]][np]--;
        f[np][pre[np]]++;
        np=pre[np];
    }
    return 1;
}
pair<int,double> mcmf(int n){
    int f=0;
    double ret=0,co;
    while(spfa(n,co)){
        f++;
        ret+=co;
    }
    return MP(f,ret);
}
int main(){
    DRI(n);
    REP(i,n){
        RII(xi[i],yi[i]);
    }
    REP(i,n){
        adde(0,i+1,2,0);
    }
    REP(i,n){
        adde(i+n+1,2*n+1,1,0);
    }
    REP(i,n)REP(j,n){
        if(i==j)continue;
        if(yi[i]>yi[j]){
            adde(i+1,j+n+1,1,dist(i,j));
        }
    }
    pair<int,double> ret=mcmf(2*n+2);
    if(ret.F!=n-1)puts("-1");
    else printf("%.15lf\n",ret.S);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread