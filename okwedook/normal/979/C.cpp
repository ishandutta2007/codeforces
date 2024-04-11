#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

graph G;
ll cnt = 0;
vector<bool> used;
vector<bool> mark;
vector<ll> sub;
ll n, x, y;

void dfs(ll v) {
    sub[v] = 1;
    used[v] = true;
    for (auto i : G[v])
        if (!used[i]) { 
            dfs(i);
            sub[v] += sub[i];
        }
}

bool dfsmark(ll v) {
    used[v] = true;
    if (v == y) {
        mark[v] = true; 
        return true;
    }
    for (auto i : G[v])
        if (!used[i])
            if (dfsmark(i)) {
                mark[v] = true; 
                return true;
            }
    return false;
} 

int main() {
    FAST;
    cin >> n >> x >> y;
    --x, --y;
    used = vector<bool>(n);
    sub = vector<ll>(n);
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    cnt = n * (n - 1);
    mark = vector<bool>(n);
    dfsmark(x);
    used = mark;
    dfs(x);
    dfs(y);
    cout << cnt - sub[x] * sub[y];
    return 0;
}