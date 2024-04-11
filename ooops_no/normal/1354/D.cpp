#include <bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")   */

//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ss second
#define ff first
//#define int long long
//#define double long double
#define pb push_back

const int N = 1e6 + 51, MOD = 1e9 + 7, mod = 998244353, INF = 3e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int t[N];

void inc (int i, int delta) {
    for(; i < N; i |= (i + 1)) t[i] += delta;
}

int sum (int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) ans += t[i];
    return ans;
}

signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, x;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        inc(x, 1);
    }
    while (q--) {
        cin >> x;
        if (x >= 0) inc(x, 1);
        else {
            x = abs(x);
            int l = 0, r = N, m;
            while (r - l > 1) {
                m = (r + l) >> 1;
                if (sum(m) >= x) r = m;
                else l = m;
            }
            inc(r, -1);
        }
    }
    for (int i = 1; i < N; i++) {
        if (t[i]) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}