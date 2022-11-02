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
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
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
typedef pair<int,int> PII;
typedef long long LL;
// }}}

int s[5010];
int in[5010];
int dp[5010][5010];
const int INF=1000000000;
int main(){
    DRI(n);
    REP1(i,1,n){
        RI(in[i]);
        s[i]=s[i-1]+in[i];
    }
    REP1(i,1,n)REP1(j,0,n)dp[i][j]=INF;
    REP1(i,1,n)dp[i][1]=i-1;
    REP1(i,1,n-1){
        int k=i,a=INF;
        REP1(j,i+1,n){
            while(k>=0&&s[i]-s[k]<=s[j]-s[i]){
                a=min(a,dp[i][k+1]);
                k--;
            }
            dp[j][i+1]=min(dp[j][i+1],a+j-i-1);
        }
    }
    int ans=INF;
    REP1(i,1,n)ans=min(ans,dp[n][i]);
    printf("%d\n",ans);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread