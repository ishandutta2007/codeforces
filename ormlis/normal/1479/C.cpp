#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

void solve() {
    int l, r;
    cin >> l >> r;
    cout << "YES\n";
    vector<ar<int, 3>> edges;
    int n = 32;
    vector<int> st(22);
    for (int i = 1; i < 22; ++i) {
        int c = n - i;
        edges.push_back({c, n, 1});
        for (int j = 1; j < i; ++j) {
            int k = n - j;
            edges.push_back({c, k, 1 << (j - 1)});
        }
        st[i - 1] = c;
    }
    int start = 1;
    if (l != 1) {
        edges.push_back({1, 2, l - 1});
        r -= l - 1;
        l = 1;
        start = 2;
    }
    int ad = 1;
    r--;
    edges.push_back({start, n, 1});
    while (r) {
        int z = 31 - __builtin_clz(r);
        edges.push_back({start, st[z], ad});
        r ^= 1 << z;
        ad += 1 << z;
    }
    cout << "32 " << edges.size() << '\n';
    for (auto &[a, b, c] : edges) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}