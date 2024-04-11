#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e18;
const ll mod = 998244353;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        a[v] = i;
    }
    ll res = 0;
    int l = a[0], r = a[0];
    for (int it = 0; it < n; ++it) {
        chmin(l, a[it]);
        chmax(r, a[it]);
        // it (it+1)

        auto f = [](int a, int l, int r) {
            // 0 a
            // 1 a-1
            // ...
            // l a-l

            return max(0, min(a, r) + min(a, l) - a + 1);
        };

        res += f(2*it+1 - (r-l+1), l, n-r-1);
        res += f(2*it+2 - (r-l+1), l, n-r-1);
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}