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
    if (n == 3) {
        cout << -1 << '\n';
        return;
    }
    int it = 1;
    if (n % 2 == 1) {
        cout << "5 4 1 2 3 ";
        it = 6;
    }
    for (; it < n; it += 2) {
        cout << it+1 << " " << it << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}