#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e9;
const ll mod = 998244353;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    sort(all(a));
    int res = 0;
    for (int i = n-2; i >= 1; --i) {
        chmax(res, (a[i+1] - a[i]) + (a[i+1] - a[0]));
    }
    for (int i = 0; i < n; ++i) {
        a[i] = 1e9 - a[i];
    }
    sort(all(a));
    for (int i = n-2; i >= 1; --i) {
        chmax(res, (a[i+1] - a[i]) + (a[i+1] - a[0]));
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