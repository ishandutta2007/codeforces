#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;

struct dsu {
    vector<int> par, sum, cnt;
    dsu(int n, vector<int>& d) {
        par.resize(n);
        cnt.resize(n, 1);
        sum = d;
        iota(all(par), 0);
    }

    int get(int u) { return par[u] == u ? u : par[u] = get(par[u]); }

    bool unite(int u, int v) {
        u = get(u), v = get(v);
        if (u == v) return false;
        sum[u] += sum[v];
        cnt[u] += cnt[v];
        par[v] = u;
        return true;
    }
    bool enough(int u) {
        u = get(u);
        return cnt[u] * cnt[u] >= sum[u];
    }
};

int que(int u) {
    cout << "? " << u+1 << endl;
    cin >> u;
    return u-1;
}

void run() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    dsu a = dsu(n, d);

    vector<int> id(n);
    iota(all(id), 0);
    stable_sort(all(id), [&d] (auto u, auto v) { return d[u] > d[v]; });

    vector<bool> used(n);

    for (int u : id) {
        if (used[u]) continue;
        used[u] = true;
        for (int it = 0; it < d[u]; ++it) {
            int v = a.get(que(u));
            a.unite(u, v);

            if (used[v]) break;
            used[v] = true;
        }
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << a.get(i) + 1 << " ";
    }
    cout << endl;
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}