#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e18;

void run() {
    ll p1, t1, p2, t2, H, s;
    cin >> p1 >> t1 >> p2 >> t2 >> H >> s;
    if (t1 > t2) {
        swap(p1, p2);
        swap(t1, t2);
    }

    vector<ll> dp(H+1, inf);
    dp[0] = 0;
    for (int h = 1; h <= H; ++h) {
        for (int i = 0; i <= h; ++i) {
            ll time = (i+1) * t1;
            time = (time + t2 - 1) / t2 * t2;

            ll rem = h - ((time / t2 - 1) * (p2 - s) + (time / t1 - 1) * (p1 - s)) - (p1 + p2 - s);
            chmin(dp[h], (rem < 0 ? 0ll : dp[rem]) + time);

            time = (i+1) * t2;
            time = (time + t1 - 1) / t1 * t1;

            rem = h - ((time / t2 - 1) * (p2 - s) + (time / t1 - 1) * (p1 - s)) - (p1 + p2 - s);
            chmin(dp[h], (rem < 0 ? 0ll : dp[rem]) + time);


            ll k = (i*t1) / t2;
            if (h <= i * (p1 - s) + k * (p2 - s))
                chmin(dp[h], i*t1);

            k = (i*t2) / t1;
            if (h <= i * (p2 - s) + k * (p1 - s))
                chmin(dp[h], i*t2);
        }
    }
    cout << dp[H] << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}