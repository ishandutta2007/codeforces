#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long 

const int mod = 1e9 + 7, N = 52;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

struct sparse {
    vector <vector <int>> t;
    vector <int> lg;
    sparse(vector <int> a) {
        int l = 0, n = a.size();
        while ((1 << l) < n) l++;
        lg.resize(n + 1);
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;
        t.resize(l + 1, vector <int>(n));
        for (int i = 0; i < n; ++i)
            t[0][i] = a[i];
        for (int i = 1; i <= l; ++i) {
            for (int j = 0; j + (1 << (i - 1)) < n; ++j) {
                t[i][j] = gcd(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int get(int l, int r) {
        int ok = lg[r - l + 1];
        return gcd(t[ok][l], t[ok][r - (1 << ok) + 1]);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        vector <int> b(n - 1);
        for (int i = 0; i < n - 1; ++i)
            b[i] = abs(a[i] - a[i + 1]);
        int ans = 1;
        sparse table(b);
        for (int i = 0; i < n - 1; ++i) {
            int l = i, r = n - 1;
            if (b[i] == 1) continue;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (table.get(i, m) > 1) l = m;
                else r = m;
            }
            ans = max(ans, l - i + 2);
        }
        cout << ans << '\n';
    }
    return 0;
}