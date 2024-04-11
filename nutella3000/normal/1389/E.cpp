#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int m, d, w;
        cin >> m >> d >> w;
        int q = w / gcd(d - 1, w);
        int cnt = (min(m, d)) / q;
        int cnt2 = (min(m, d)) % q;

        int res = cnt * (cnt - 1) / 2 * q + cnt2 * cnt;
        cout <<res << endl;
    }
}