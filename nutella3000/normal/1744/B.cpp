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
    int n, q; cin >> n >> q;
    ll s[2]{};
    ll c[2]{};
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        s[v % 2] += v;
        ++c[v % 2];
    }
    while (q--) {
        int t, x; cin >> t >> x;
        if (x & 1) {
            s[1-t] += s[t] + c[t] * x;
            c[1-t] += c[t];
            s[t] = c[t] = 0;
        } else {
            s[t] += c[t] * x;
        }
        cout << s[0] + s[1] << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}