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

const int mod=1000000007;
inline int add(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline int mul(int a,int b){
    return (a*(LL)b)%mod;
}
inline int sub(int a,int b){
    a-=b;
    if(a<0)a+=mod;
    return a;
}
int dp[2010][2010];
int dp2[2010][2010];
int n,m;
int main(){
    RII(n,m);
    REP1(j,2,m)dp[1][j]=1;
    REP1(i,2,n){
        int s=0,sj=0;
        REP1(j,1,m){
            s=add(s,dp[i-1][j]);
            sj=add(sj,mul(dp[i-1][j],j));
            dp[i][j]=sub(mul(j+1,s),sj);
        }
    }
    REP1(i,1,n)REP1(j,1,m){
        dp[i][j]=mul(dp[i][j],m-j+1);
    }
    REP1(i,1,n){
        int s=0,sj=0;
        int ss=0,ssj=0;
        PER1(j,m,2){
            dp2[i][j]=sub(sj,mul(j-1,s));
            s=add(s,dp[i-1][j]);
            sj=add(sj,mul(dp[i-1][j],j));
            ss=add(ss,dp2[i-1][j]);
            ssj=add(ssj,mul(dp2[i-1][j],j));
            dp2[i][j]=add(dp2[i][j],sub(ssj,mul(j-1,ss)));
        }
    }
    int ans=0;
    REP1(i,1,n)REP1(j,1,m){
        ans=add(ans,mul(n-i+1,dp[i][j]));
        ans=add(ans,mul(n-i+1,dp2[i][j]));
    }
    PI(ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread