#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <bitset>
#include <functional>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, L = 20;

struct Sparse {
    vector <int> lg, a;
    vector <vector <int>> t;
    Sparse(vector <int> a) : a(a) {
        int n = a.size();
        lg.resize(n + 1);
        t.resize(L, vector <int>(n));
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < n; ++i)
            t[0][i] = i;
        for (int i = 1; i < L; ++i) {
            for (int j = 0; j + (1ll << (i - 1)) < n; ++j) {
                t[i][j] = a[t[i - 1][j]] > a[t[i - 1][j + (1ll << (i - 1))]]
                    ? t[i - 1][j] : t[i - 1][j + (1ll << (i - 1))];
            }
        }
    }
    int get(int l, int r) {
        int len = (1ll << lg[r - l + 1]), ln = lg[r - l + 1];
        return a[t[ln][l]] > a[t[ln][r - len + 1]] ? t[ln][l] : t[ln][r - len + 1];
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
    int n, q; cin >> n >> q;
    vector <int> a(n), d(n - 1);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n - 1; ++i)
        d[i] = abs(a[i] - a[i + 1]);

    Sparse table(d);
    auto rec = [&](int l, int r, auto rec) -> int {
        if (l == r) return 0;
        int id = table.get(l, r - 1);
        return d[id] * (id + 1 - l) * (r - id) + rec(l, id, rec) + rec(id + 1, r, rec);
    };

    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        cout << rec(l, r, rec) << '\n';
    }
    return 0;
}