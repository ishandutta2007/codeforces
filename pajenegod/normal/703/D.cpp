// not my code
// https://codeforces.com/contest/703/submission/92019923

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 
 
using namespace __gnu_pbds;
using namespace std;
 
 
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<ll> sl;
typedef multiset<ll> msl;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;
 
#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repk(i, k, n) for(int i = k; i < n; ++i)
 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
 
#define popcnt __builtin_popcount
#define gcd std::__detail::__gcd
#define lcm std::__detail::__lcm
const int INFI = 1e9 + 5;
const ll INFL = 4e18 + 5;
 
// LIORZ LIORZ LIORZ LIORZ LIORZ
 
int n; const int maxn = 1e6 + 5;
vpi g[maxn]; ll a[maxn] = { 0 }; ll fen[maxn] = { 0 }; ll xpre[maxn] = { 0 }; ll ans[maxn] = { 0 };
unordered_map<ll, ll> last; ll everything = 0;
 
void _update(int pos, ll val) // fen[pos] ^= val
{
    pos++;
    for(int i = pos; i <= n; i += (i & (-i)))
        fen[i] ^= val;
}
ll _query(int pos)
{
    pos++; ll res = 0;
    for(int i = pos; i > 0; i -= (i & (-i)))
        res ^= fen[i];
    return res;
}
void solve()
{
    cin >> n; xpre[0] = 0;
    for(int i = 0 ; i < n; ++i)
    {
        cin >> a[i];
        xpre[i+1] = xpre[i] ^ a[i];
    }
    int m; cin >> m;
    rep(i, m)
    {
        int l, r;
        cin >> l >> r; l--; r--;
        g[r].emplace_back(l, i);
    }
    rep(i, n)
    {
        if(last.find(a[i]) != last.end())
            _update(last[a[i]], a[i]);
        else
            everything ^= a[i];
        _update(i, a[i]);
        last[a[i]] = i;
        for(auto e : g[i])
            ans[e.se] = _query(e.fi-1) ^ everything  ^ xpre[i+1] ^ xpre[e.fi];
    }
    rep(i, m)
        cout << ans[i] << '\n';
}
 
signed main()
{
    GOGOGO
    //cout << fixed << setprecision(9);
    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}
 
/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/