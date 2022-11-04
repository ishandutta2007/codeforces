#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;

const int INF = 1e9;

inline ll sum(int x) {
    return 1LL * x * (x + 1) / 2;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, m, a, b;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> m >> a >> b;

    vector <int> x(a, INF);
    vector <int> d(a, INF);

    x[0] = d[0] = 0;

    int pos = a, mx = 0;
    while(pos != 0) {
        mx = max(mx, pos);

        if(pos >= b) {
            pos -= b;
        }
        else {
            pos += a;
        }

        if(pos > m) {
            break;
        }

        int r = pos % a;
        x[r] = min(x[r], mx);
        d[r] = min(d[r], pos);
    }

    ll ans = 0;
    for(int r = 0; r < a; r++) {
        if(x[r] > m) {
            continue;
        }

        //cerr << r << " " << x[r] << " " << d[r] << " ";

        ll cur;
        // cur = sum( (j - d[r]) / a + 1 , x[r] <= j <= m);

        cur = m - x[r] + 1;

        int mn = min(m - x[r] + 1, (r - x[r] % a + a) % a);
        if(mn == 0) {
            mn = min(m - x[r] + 1, a);
        }
        cur += 1LL * ((x[r] - d[r]) / a) * mn;

        int len = (m - x[r] + 1 - mn) / a;
        cur += 1LL * a * (sum(len + (x[r] - d[r]) / a) - sum((x[r] - d[r]) / a));

        cur += 1LL * (m - x[r] + 1 - mn - len * a) * (len + 1 + (x[r] - d[r]) / a);

        //cerr << mn << "\n";

        ans += cur;
    }

    cout << ans;

    return 0;
}