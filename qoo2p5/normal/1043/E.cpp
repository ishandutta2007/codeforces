#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

// Solution

const int N = (int) 3e5 + 123;

struct Fenwick {
    ll f[N];

    void add(int i, ll v) {
        i++;
        for (; i < N; i += i & (-i)) {
            f[i] += v;
        }
    }

    ll get(int r) {
        r++;
        ll res = 0;
        for (; r > 0; r -= r & (-r)) {
            res += f[r];
        }
        return res;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int n, m;
vector<int> g[N];

ll x[N], y[N];
Fenwick fx, fy, cnt;
int pos[N];
ll ans[N];

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        g[i].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<int, int>> ord;
    for (int i = 1; i <= n; i++) {
        ord.emplace_back(x[i] - y[i], i);
    }
    sort(ord.begin(), ord.end());
    for (int i = 0; i < n; i++) {
        pos[ord[i].second] = i;
        fx.add(i, x[ord[i].second]);
        fy.add(i, y[ord[i].second]);
    }
    for (int i = 0; i < n; i++) {
        cnt.add(i, 1);
    }

    for (int i = 0; i < n; i++) {
        int id = ord[i].second;

        for (int v : g[id]) {
            int j = pos[v];
            fx.add(j, -x[v]);
            fy.add(j, -y[v]);
            cnt.add(j, -1);
        }
        ans[id] += y[id] * 1LL * cnt.get(0, i) + fx.get(0, i);
        ans[id] += x[id] * 1LL * cnt.get(i + 1, n - 1) + fy.get(i + 1, n - 1);

        for (int v : g[id]) {
            int j = pos[v];
            fx.add(j, x[v]);
            fy.add(j, y[v]);
            cnt.add(j, 1);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}