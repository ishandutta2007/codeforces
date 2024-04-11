// Not my code https://codeforces.com/contest/894/submission/98619192

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
 
template<class T> using func = function<T>;
 
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
 
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}
 
// LIORZ LIORZ LIORZ LIORZ LIORZ
 
//#define BRUH_WHY_TESTCASES
const int maxn = 1e6 + 5;
const int maxm = 1e5 + 5;
int g[maxn];
int n; int m;
int d[maxn];
struct dsdata {
    vi data; vl prefix;
    pl query(int h) {
        auto it = lower_bound(all(data), h+1ll);
        int cnt =  it -data.begin();
        return {prefix[cnt], cnt};
    }
} ds[maxn];
void dfs(int c, ll dd = 0) {
    d[c] = dd;
    ds[c].prefix.pb(0);
    ds[c].data.pb(d[c]);
    if(2*c -1 < n) {
        dfs(2*c, dd + g[2*c - 1]); copy(all(ds[2*c].data), back_inserter(ds[c].data));
    }
    if(2*c < n) {
        dfs(2*c + 1, dd + g[2*c]); copy(all(ds[2*c+1].data), back_inserter(ds[c].data));
    }
    sort(all(ds[c].data)); // this can be optimize with std::merge
    for(int i = 1; i <= ds[c].data.size(); ++i) {
        ds[c].prefix.pb(ds[c].prefix[i-1] + (ll)ds[c].data[i-1]);
    }
}
void solve() {
    cin >> n >> m;
    aread(g+1, n-1);
    dfs(1);
    rep(i, m) {
        ll a, h; cin >> a >> h;
        ll old = a; ll offset = 0;
        auto q = ds[a].query(h + d[a] - 1);
        ll res = q.fi - d[a] * q.se;
        ll tot = q.se;
        while(old != 1)
        {
            offset += g[old-1];
            auto q1 = ds[old/2].query(h + d[old/2] - offset - 1); auto q2 = ds[old].query(h + d[old/2] - offset - 1);
            res += q1.fi - q2.fi + (offset - d[old/2]) * (q1.se - q2.se);
            tot += q1.se - q2.se;
            old /= 2;
        }
        cout << h * tot - res << '\n';
    }
}
 
int main()
{
    GOGOGO
    int t=1;
    #ifdef BRUH_WHY_TESTCASES
        cin >> t;
    #endif
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