#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

bool vis[3000];
void dfs(int u, vector<int>& a) {
    vis[u]=1;
    if (u<a.size()) {
        for (int i=0; i<30; ++i)
            if ((a[u]&(1<<i))&&!vis[a.size()+i])
                dfs(a.size()+i, a);
    } else {
        for (int i=0; i<a.size(); ++i)
            if (!vis[i]&&(a[i]&(1<<(u-a.size()))))
                dfs(i, a);
    }
}

bool ck(vector<int> a) {
    memset(vis, 0, sizeof(vis));
    dfs(0, a);
    for (int i=0; i<a.size(); ++i)
        if (!vis[i])
            return 0;
    return 1;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = max(a[i], 1);

    auto good = [&](vector<int> v) {
        return ck(v);
    };

    auto pr = [&](vector<int> v) {
        int ans = 0;
        for (int i = 0; i < n; i++) ans += abs(a[i] - b[i]);
        cout << ans << '\n';
        for (int x : v) cout << x << ' ';
        cout << '\n';
    };

    if (good(b)) {
        pr(b);
        return;
    }

    for (int i = 0; i < n; i++) {
        b[i]--;
        if (good(b)) {
            pr(b);
            return;
        }
        b[i]++;

        b[i]++;
        if (good(b)) {
            pr(b);
            return;
        }
        b[i]--;
    }

    // you need two ops, pick the thing with the highest LSB
    vector<int> loc[30];
    for (int i = 0; i < n; i++) {
        loc[__builtin_ctz(a[i])].push_back(i);
    }
    for (int i = 29; i >= 0; i--) if (sz(loc[i])) {
        assert(sz(loc[i]) >= 2);
        int x = loc[i][0];
        int y = loc[i][1];
        b[x]--, b[y]++;
        assert(good(b));
        pr(b);
        break;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}