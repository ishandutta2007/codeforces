#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;


void run() {
    int n; string s;
    cin >> n >> s; s += '0';
    vector<int> a(n+1);
    int res = 0;
    int prv = -1, mn = inf;
    for (int i = 0; i <= n; ++i) {
        if (i != n) cin >> a[i];
        if (s[i] == '1') {
            res += a[i];

            chmin(mn, a[i]);
            if (prv == -1) {
                prv = i ? a[i-1] : 0;
            }
        }
        if (s[i] == '0') {
            if (prv != -1) {
                res += max(0, prv - mn);
                prv = -1;
                mn = inf;
            }
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