#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;
const ll mod = 998244353;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i; --i;
    }

    int res = 0;
    for (int len = n/2; len; len /= 2) {
        for (int st = 0; st < n; st += 2 * len) {
            if (a[st] > a[st + len]) {
                for (int i = 0; i < len; ++i) {
                    swap(a[st + i], a[st + len + i]);
                }
                ++res;
            }
        }
    }
    vector<int> b = a;
    sort(all(b));
    if (a == b) cout << res << '\n';
    else cout << -1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}