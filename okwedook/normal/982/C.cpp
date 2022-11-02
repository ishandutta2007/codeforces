#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
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
vector<int> sub;
vector<bool> used;
ll cnt = 0;

void dfs(int v) {
    used[v] = true;
    sub[v] = 1;
    for (auto i : G[v])
        if (!used[i]) {
            dfs(i);
            sub[v] += sub[i];
            if (sub[i] % 2 == 0) ++cnt;
        }
}

int main() {
    FAST;
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }
    G = graph (n);
    sub = vector<int>(n);
    used = vector<bool>(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    int head;
    for (int i = 0; i < n; ++i) 
        if (G[i].size() == 1) head = i;
    dfs(head);
    cout << cnt;
    return 0; 
}