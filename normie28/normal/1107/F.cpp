
// Problem : J. Moonwalk challenge
// Contest : Codeforces - Bubble Cup 11 - Finals [Online Mirror, Div. 1]
// URL : https://codeforces.com/contest/1045/problem/J
// Memory Limit : 256 MB
// Time Limit : 6000 ms
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

struct Credit{
    int a, b, k;
 
    bool operator< (const Credit& c) const
    {
        return b > c.b;
    }
};
 
int N;
vector<Credit> a;
vector<ll> dp;
 
void ReadData();
void Solve();
 
int main()
{
    ReadData();
    Solve();
 
    return 0;
}
 
void ReadData()
{
   // ifstream cin("file.in");
 
    cin >> N;
    a = vector<Credit>(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i].a >> a[i].b >> a[i].k;
}
 
void Solve()
{
    sort(a.begin(), a.end());
 
    dp = vector<ll>(N + 1);
    for (const Credit& c : a)
    {
        for (int i = N - 1; i >= 0; --i)
        {
            dp[i + 1] = max(dp[i + 1], dp[i] + c.a - 1ll*i*c.b);
            dp[i] = max(dp[i], dp[i] + c.a - 1ll*c.k*c.b);
        }
    }
 
    ll ans{0};
    for (int i = 0; i <= N; ++i)
        ans = max(ans, dp[i]);
 
    cout << ans << '\n';
}