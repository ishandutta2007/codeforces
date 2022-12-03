#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double old;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        if (x % d == y % d) {
            cout << abs(x - y) / d << '\n';
            continue;
        }
        int ans = -1;
        if (y % d == 1) {
            ans = (x - 1 + d - 1) / d;
            ans += (y - 1) / d;
        }
        if (y % d == n % d) {
            int t;
            t = (abs(x - n) + d - 1) / d;
            t += (n - y) / d;
            if (ans == -1 || t < ans) {
                ans = t;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}