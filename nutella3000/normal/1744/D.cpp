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
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        while (!(v & 1)) {
            v /= 2;
            ++cnt;
        }
    }
    vector<int> id(n);
    iota(all(id), 1);
    sort(all(id), [](int u, int v) { return __builtin_ctz(u) > __builtin_ctz(v); });

    int res = 0;
    for (auto i : id) {
        if (cnt < n) {
            cnt += __builtin_ctz(i);
            ++res;
        }
    }
    cout << (cnt < n ? -1 : res) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}