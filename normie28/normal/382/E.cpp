
// Problem : E. Neatness
// Contest : Codeforces - Codeforces Round #209 (Div. 2)
// URL : https://codeforces.com/contest/359/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//

const int MAXN=55;
const int Mod=1000000007;
int c[MAXN][MAXN],dp[MAXN][MAXN][2];
void build()
{
    for(int i=0;i<MAXN;i++)
        for(int j=(c[i][0]=1);j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
    dp[0][0][0]=dp[1][0][1]=1;
    for(int i=2;i<MAXN;i++)
        for(int j=0;j<=i-1-j;j++)
            for(int k=0;k<MAXN;k++)
                for(int l=0;l<=k;l++)
                {
                    int tmp=1LL*max(j,1)*max(i-1-j,1)*(j==i-1-j ? c[i-2][j-1] : c[i-1][j])%Mod;
                    dp[i][k][1]=(dp[i][k][1]+1LL*dp[j][l][0]*dp[i-1-j][k-l][0]%Mod*tmp)%Mod;
                    if(k<MAXN-1)
                    {
                        dp[i][k+1][0]=(dp[i][k+1][0]+1LL*dp[j][l][0]*dp[i-1-j][k-l][1]%Mod*tmp)%Mod;
                        dp[i][k+1][0]=(dp[i][k+1][0]+1LL*dp[j][l][1]*dp[i-1-j][k-l][0]%Mod*tmp)%Mod;
                        dp[i][k+1][0]=(dp[i][k+1][0]+1LL*dp[j][l][1]*dp[i-1-j][k-l][1]%Mod*tmp)%Mod;
                    }
                }
}
int main()
{
    fio;
    build();
    int n,k;
    cin>>n>>k;
    cout<<(dp[n][k][0]+dp[n][k][1])%Mod;
}