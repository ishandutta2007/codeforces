 #pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

const ll N = 400000;
ll fenv[N + 1];

void add(int r, ll x) {
    checkmin(r, N - 1);
    for (; r < N; r |= r + 1) fenv[r] += x;
}

ll get(int r) {
    ll ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ans += fenv[r];
    return ans;
}

ll get(ll l, ll r) {
    return get(r) - get(l - 1);
}

ll n;
vector<vector<pll>> act;
graph G;
vector<ll> ans;

void dfs(int v, int d = 0, int p = -1) {
    for (auto i : act[v])
        add(d + i.f, i.s);
    ans[v] = get(d, N);
    for (auto i : G[v])
        if (i != p) 
            dfs(i, d + 1, v);
    for (auto i : act[v])
        add(d + i.f, -i.s);
}


signed main() {
    FAST; FIXED; RANDOM;
    cin >> n;
    G.resize(n);
    act.resize(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int m;
    cin >> m;
    while (m--) {
        ll v, d, x;
        cin >> v >> d >> x;
        act[v - 1].pb({d, x});
    }
    ans.resize(n);
    dfs(0);
    for (auto i : ans) cout << i << ' ';
    return 0;
}