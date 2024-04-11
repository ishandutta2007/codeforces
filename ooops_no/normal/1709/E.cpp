#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 2e5 + 10;
int ans = 0;
vector<int> g[N], a(N), xr(N);
set<int> st[N];

void dfs(int v, int p) {
    vector<int> arr;
    for (auto to : g[v]) {
        if (to != p) {
            dfs(to, v);
            arr.pb(to);
        }
    }
    sort(arr.begin(), arr.end(), [&](int i, int j){return st[i].size() > st[j].size();});
    if (arr.size() == 0) {
        st[v].insert(a[v]);
    } else {
        int u = arr[0];
        xr[v] = (xr[u] ^ a[v]);
        swap(st[v], st[u]);
        st[v].insert(xr[v] ^ a[v]);
        bool good = 1;
        if (st[v].find(xr[v]) != st[v].end()) {
            good = 0;
        }
        for (int i = 1; i < arr.size(); i++) {
            int vert = arr[i];
            for (auto to : st[vert]) {
                if (st[v].find(to ^ xr[vert] ^ xr[v]) != st[v].end()) {
                    good = 0;
                }
            }
            for (auto to : st[vert]) {
                st[v].insert(to ^ xr[vert] ^ xr[v] ^ a[v]);
            }
        }
        if (!good) {
            ans++;
            st[v].clear();
            xr[v] = 0;
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}