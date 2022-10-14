#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct DSU {
    int n;
    vector<lint> p;
    vector<lint> sz;
    
    DSU(int _n) : n(_n) {
        p.resize(n), sz.resize(n);
        iota(begin(p), end(p), 0);
        for (int i = n / 2; i < n; i++) {
            sz[i] = 1; // use switch, so ans++
        }
    }

    inline int get(int n) {
        return p[n] == n ? n : p[n] = get(p[n]);
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            sz[y] += sz[x];
            return true;
        }
        return false;
    }

};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<vector<int>> A(N);

    for (int i = 0; i < K; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            a--;
            A[a].push_back(i);
        }
    }

    lint ans = 0;
    DSU dsu(2 * K);

    auto invert = [&](int n) { // [0, K) = don't use switch, [K, 2K) = use switch
        return n < K ? n + K : n - K;
    };

    auto unite = [&](int x, int y) {
        x = dsu.get(x);
        y = dsu.get(y);
        if (x != y) {
            ans -= min(dsu.sz[x], dsu.sz[invert(x)]);
            ans -= min(dsu.sz[y], dsu.sz[invert(y)]);
            dsu.unite(x, y);
            dsu.unite(invert(x), invert(y));
            ans += min(dsu.sz[y], dsu.sz[invert(y)]);
        }
    };

    for (int i = 0; i < N; i++) {
        if (A[i].size() == 1) {
            int x = A[i][0];
            x = dsu.get(S[i] == '0' ? x : invert(x));
            ans -= min(dsu.sz[x], dsu.sz[invert(x)]);
            dsu.sz[x] = (int) 1e9; // cannot take
            ans += min(dsu.sz[x], dsu.sz[invert(x)]);
        } else if (A[i].size() == 2) {
            int x = A[i][0];
            int y = A[i][1];
            if (S[i] == '1') {
                unite(x, y);
            } else {
                unite(x, invert(y));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}