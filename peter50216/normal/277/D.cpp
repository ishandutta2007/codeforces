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

pair<LL,double> dp[2000][2000];
//int used[2][1570];
//int allu[2][1570],ac[2];
//const double eps=1e-12;
struct XD{
    int scs,scl,ts,tl;
    double prf;
    LL prll;
    bool operator<(const XD& b)const{
        if(prll==1000000)return 0;
        if(b.prll==1000000)return 1;
        return prll*tl*(1000000-b.prll)<b.prll*b.tl*(1000000-prll);
    }
}in[1010];
/*
int uid;
inline pair<double,double>& gd(int c,int a){
    if(used[c][a]!=uid){
        used[c][a]=uid;
        allu[c][ac[c]]=a;
        ac[c]++;
        dp[c][a]=MP(-1,0);
    }
    return dp[c][a];
}*/
inline void update(pair<LL,double>& a,const pair<LL,double>& b){
    a=max(a,b);
}
int main(){
    DRII(n,t);
    REP(i,n){
        RII(in[i].scs,in[i].scl);
        RII(in[i].ts,in[i].tl);
        scanf("%lf",&in[i].prf);
        in[i].prll=(LL)(in[i].prf*1000000+0.5);
    }
    sort(in,in+n);
    //uid=1;
    //ac[0]=ac[1]=0;
//    int c1=0,c2=1;
    REP1(i,0,n)REP1(j,0,t)dp[i][j].F=-1;
    dp[0][0]=MP(0,0.0);
    REP(i,n){
        REP1(st,0,t){
            if(dp[i][st].F<0)continue;
            {
                pair<LL,double>& d=dp[i+1][st];
                update(d,dp[i][st]);
            }
            if(st+in[i].ts<=t){
                pair<LL,double>& d=dp[i+1][st+in[i].ts];
                pair<LL,double> p=dp[i][st];
                p.F+=in[i].scs*1000000LL;
                update(d,p);
            }
            if(st+in[i].ts+in[i].tl<=t){
                pair<LL,double>& d=dp[i+1][st+in[i].ts+in[i].tl];
                pair<LL,double> p=dp[i][st];
                p.F+=in[i].scs*1000000LL+(1000000-in[i].prll)*in[i].scl;
                p.S+=in[i].tl;
                p.S*=in[i].prf;
                update(d,p);
            }
        }
    }
    LL a1=0;
    double b1=0;
    REP1(st,0,t){
        //int st=allu[c1][j];
        LL aa=dp[n][st].F;
        double bb=st-dp[n][st].S;
        if(aa<0)continue;
        if(a1<aa||(a1==aa&&b1>bb)){
            a1=aa;
            b1=bb;
        }
    }
    printf("%.15lf %.15lf\n",a1/1000000.0,b1);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread