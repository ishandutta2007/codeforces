
// Problem : E. Ski Accidents
// Contest : Codeforces - Codeforces Global Round 8
// URL : https://codeforces.com/contest/1368/problem/E
// Memory Limit : 512 MB
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
ll n, m;
ll used[200001], dp[200001], anti[200001], pred[200001];
vector<int> a[200001];
 
 
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
ll fi(ll k) {
    ll cnt = 0;
    for (ll i = 2; i < k; i++) {
        if (gcd(i, k) == 1) {
            cnt++;
        }
    }
    return cnt;
 }
 
 ll binpow (ll a, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow (a, n-1) * a) % m;
    else {
        ll b = (binpow (a, n/2)) % m;
        return (b * b) % m;
    }
}
 
 
int main() 
{
	fio;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        used[x] = 1;
    }
    ll q = fi(m);
    for (ll i = 0; i < m; i++)
    {
        anti[i] = binpow(i, q);
        if (!used[i])
            a[gcd(i, m)].push_back(i);
    }
    for (ll i = m; i >= 1; i--)
    {
        dp[i] = a[i].size();
        for (ll j = i * 2; j <= m; j += i)
        {
            if (!(a[j].size() == 0))
            {
                if (dp[j] + a[i].size() > dp[i])
                {
                    dp[i] = dp[j] + a[i].size();
                    pred[i] = j;
                }
            }
        }
    }
    cout << dp[1] << "\n";
    ll i = 1, last = 1, p = 1;
    while (i != 0)
    {
        for (ll j : a[i])
        {
            ll f = 0;
            if (j != 0)
            {
                ll d = gcd(m, last);
                f = ((j / d) * (anti[last / d])) % m;
            }
            p = (p * f) % m;
            cout << f << " ";
            last = j;
        }
        i = pred[i];
    }
}