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
    vector<int> a(n), b(n);
    int c = 0;
    for (auto& i : a) {
        cin >> i;
        c += i;
    }
    for (auto& i : b) {
        cin >> i;
        c -= i;
    }
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if ((c > 0) ^ (a[i] == 1)) {
                bad = true;
            }
        }
    }
    cout << abs(c) + bad << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}