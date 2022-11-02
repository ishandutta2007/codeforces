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
    int n; char col; string s;
    cin >> n >> col >> s;
    s += s;
    int lst = -1, res = 0;
    for (int i = 0; i < 2*n; ++i) {
        if (s[i] == col && lst == -1) lst = i;
        if (s[i] == 'g' && lst != -1) {
            chmax(res, i - lst);
            lst = -1;
        }
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