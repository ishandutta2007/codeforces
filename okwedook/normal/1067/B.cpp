#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
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
#define mod 998244353
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

graph G;
int head;
ll n, k;
bool dfscheck(int v, int p, int d) {
    if (G[v].size() == 1) 
        return d == k;
    if (G[v].size() < 3 + (p != -1))
        return false;
    for (auto i : G[v])
        if (i != p)
            if (!dfscheck(i, v, d + 1))
                return false;
    return true;
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> k;
    if (n < 4) {
        cout << "No";
        return 0;
    }
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    deque<int> que;
    vector<bool> used(n);
    vector<int> near(n);
    for (int i = 0; i < n; ++i)
        if (sz(G[i]) == 1) que.pb(i), used[i] = true, near[i] = 0;
    while (sz(que) > 0) {
        int fr = que.front();
        que.popf();
        for (auto i : G[fr])
            if (!used[i]) {
                used[i] = true;
                near[i] = near[fr] + 1;
                que.pb(i);
            }
    }
    int ind = 0;
    for (int i = 0; i < n; ++i)
        if (near[i] > near[ind])
            ind = i;
    if (near[ind] != k) {
        cout << "No";
        return 0;
    }
    if (dfscheck(ind, -1, 0)) cout << "Yes";
    else cout << "No";
    return 0;
}