#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }


void run() {
    bool s_only = true;
    bool t_only = true;
    ll cnt = 0;
    int q; cin >> q;

    while (q--) {
        int d, k; cin >> d >> k;
        string x; cin >> x;
        bool only = x.find_first_not_of('a') >= x.size();
        if (d == 1) {
            s_only &= only;
            cnt += (ll)x.size() * k;
        } else {
            t_only &= only;
            cnt -= (ll)x.size() * k;
        }
        cout << (!t_only || (s_only && cnt < 0) ? "YES" : "NO") << '\n';
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