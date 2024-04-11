#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define all(s) begin(s), end(s)
#define bit1(s) __builtin_popcountll(s)
 
#define Error(s) freopen(s, "w", stderr)
 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
 
 
const ll MOD = 1E9 + 7; // 998244353
const ll inf = LONG_LONG_MAX;
const ll n_inf = LONG_LONG_MIN;
const ld PI = 3.141592653589793238462643;
 

class DisjointSetsUnion
{
 
public:
    vector<ll> p;
    DisjointSetsUnion(ll n) : p(n + 1, -1)
    { /* constructor declare a DSU */
    }
    ll Find(ll x)
    {
        return p[x] < 0 ? x : Find(p[x]);
    }
    void Union(ll x, ll y)
    {
        if ((x = Find(x)) == (y = Find(y)))
            return;
        if (p[y] < p[x]) 
            swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }
    ll Rank(ll x)
    {
        return (p[x] < 0) ? -p[x] : 0;
    }
    bool Check(ll x, ll y)
    {
        return Find(x) == Find(y) ? true : false;
    }
    void Print() // for debugging.
    {
        for (ll i = 1; i < p.size(); i++)
        {
            fprintf(stderr, "Node %lld: %lld\n", i, p[i]);
        }
    }
};
 
int main()
{
    long long n;
    cin >> n;
    vl a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(all(a));
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        auto itr = upper_bound(all(a), 2 * a[i]) - a.begin() - i - 1;
        ans += itr;
    }
    cout << ans;
    return 0;
}