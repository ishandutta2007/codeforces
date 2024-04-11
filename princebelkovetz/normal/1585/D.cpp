#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 4e2 + 2;

struct Fenwick {
    int n;
    vector <int> t;
    Fenwick(int n) : n(n) {
        t.resize(n);
    }
    int get(int i) {
        int res = 0;
        for (; i >= 0; i &= i + 1, --i)
            res += t[i];
        return res;
    }
    void inc(int i) {
        for (; i < n; i |= i + 1)
            t[i]++;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        Fenwick tree(n + 1);
        int inv = 0;
        set <int> was;
        for (int i = n - 1; i >= 0; --i) {
            if (was.find(a[i]) != was.end()) {
                inv = 0;
                break;
            }
            was.insert(a[i]);
            inv += tree.get(a[i]);
            tree.inc(a[i]);
        }
        cout << (inv & 1 ? "NO" : "YES") << '\n';
    }
}