#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "petrol.inp"
#define FILE_OUT "petrol.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define endl "\n"
typedef long long ll;
//-------------HASH----------//
//-------------END-----------//
int n,m,i,j,k,t,t1,p,aad,bad,bruh[30],cnt=0,maxx=0;
int dp[4][10000001],a[10001],back[10001],ma[10001],pr[1001],tab[11]={2,3,5,7,11,13,17,19,23,29,31};
string s,md[5001];
vector<int> v;
int calc(int a)
{
    int res=-1;
    for (int i=1;i<=1000;i++) if ((a%i==0)and(pr[i])) res=i;
    return res;
}
int cmp(int a, int b)
{
    return (calc(a)<calc(b));
}
int main(){
  //  ofile;
    nfio;
    cin>>n;
    dp[0][0]=1;
    for (i=1;i<=n;i++)
    {
        dp[0][i]=((dp[1][i-1]+dp[2][i-1])%MOD)+dp[3][i-1];
        dp[1][i]=((dp[2][i-1]+dp[3][i-1])%MOD)+dp[0][i-1];
        dp[2][i]=((dp[3][i-1]+dp[1][i-1])%MOD)+dp[1][i-1];
        dp[3][i]=((dp[0][i-1]+dp[0][i-1])%MOD)+dp[2][i-1];
        dp[0][i]%=MOD;
        dp[1][i]%=MOD;
        dp[2][i]%=MOD;
        dp[3][i]%=MOD;
    }
    cout<<dp[0][n];
}