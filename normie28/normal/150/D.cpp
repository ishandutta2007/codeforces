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
#define MaxN 151
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
#define oo 1e8
typedef long long ll;
//---------END-------//
char s[MaxN+2];
int dp[MaxN+1][MaxN+1][MaxN+1];
int best[MaxN+1][MaxN+1];
int suff[MaxN+1];
int a[MaxN+1];
int N,M;
 
int main(){
 
 fio;
    int i,j,t,p,k,len,x;
 
 cin>>N;
    for(i = 1; i <= N; ++i) cin>>a[i];
    cin>>s;
 
    for(i = N; i >= 1; --i) s[i] = s[i-1];
    for(i = 1; i <= N; ++i)
        if(a[1] > -1) dp[i][i][0] = a[1];
        else dp[i][i][0] = -oo;
 
    for(t = 2; t <= N; ++t)
        for(i = 1; i <= N-t+1; ++i)
        {
            j = i+t-1;
            for(k = 0; k <= N; ++k) dp[i][j][k] = -oo;
            for(len = 1; len <= t; ++len)
            {
                if(s[i] == s[j] && len > 1) dp[i][j][len] = max(dp[i][j][len], dp[i+1][j-1][len-2]);
                for(p = i+len-1; p < j; ++p) dp[i][j][len] = max(dp[i][j][len], dp[i][p][len] + dp[p+1][j][0]);
                for(p = j-len+1; p > i; --p) dp[i][j][len] = max(dp[i][j][len], dp[i][p-1][0] + dp[p][j][len]);
 
                if(a[len] > -1) dp[i][j][0] = max(dp[i][j][0], dp[i][j][len] + a[len]);
            }
        }
 
    for(i = 1; i <= N; ++i)
        for(j = i; j <= N; ++j)
            for(k = 0; k <= j-i+1; ++k)
            best[i][j] = max(best[i][j], dp[i][j][k]);
 
    for(j = 1; j <= N; ++j)
        for(i = j; i >= 1; --i)
        suff[j] = max(suff[j], suff[i-1] + best[i][j]);
 
 cout<<suff[N]<<endl;
}