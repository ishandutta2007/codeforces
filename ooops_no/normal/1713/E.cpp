#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

struct dsu {
    vector<int> par;
    dsu(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find_set(int v) {
        if (v == par[v]) {
            return v;
        } else {
            return par[v] = find_set(par[v]);
        }
    }
    bool union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) {
            return 0;
        } else {
            par[b] = a;
            return 1;
        }
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        dsu g(2 * n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i][j] == a[j][i]) continue;
                if (a[i][j] < a[j][i]) {
                    if (g.find_set(2 * i) != g.find_set(2 * j + 1)) {
                        g.union_set(2 * i, 2 * j);
                        g.union_set(2 * i + 1, 2 * j + 1);
                    }
                } else if (g.find_set(2 * i) != g.find_set(2 * j)) {
                    g.union_set(2 * i, 2 * j + 1);
                    g.union_set(2 * i + 1, 2 * j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g.find_set(2 * i) == g.find_set(2 * j + 1)) {
                    swap(a[i][j], a[j][i]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}