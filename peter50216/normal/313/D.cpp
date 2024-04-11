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

LL dp[310][310];
LL minv[310][310];
const LL INF=1000000000000000000LL;
int main(){
    DRIII(n,m,k);
    REP1(i,0,n)REP1(j,0,n)minv[i][j]=INF;
    REP1(i,0,n)REP1(j,0,n)dp[i][j]=INF;
    REP(i,m){
        DRIII(l,r,c);
        minv[l][r]=min(minv[l][r],(LL)c);
    }
    PER1(l,n,1){
        REP1(j,0,n-l){
            minv[j+1][j+l]=min(minv[j][j+l],minv[j+1][j+l]);
            minv[j][j+l-1]=min(minv[j][j+l],minv[j][j+l-1]);
        }
    }
    dp[0][0]=0;
    REP1(i,0,n-1){
        REP1(j,0,n){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            REP1(k,i+1,n){
                dp[k][j+k-i]=min(dp[k][j+k-i],dp[i][j]+minv[i+1][k]);
            }
        }
    }
    LL ans=INF;
    REP1(j,k,n)ans=min(ans,dp[n][j]);
    if(ans==INF)ans=-1;
    printf("%I64d\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread