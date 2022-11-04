#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

const ll INF = 1e18;
const int MAXN = (int)2e5;

ll aint[2][4 * MAXN + 1];

void update(int nod, int left, int right, int l, int r, ll val, bool t) {
    if (l <= left && right <= r) {
        aint[t][nod] = min(aint[t][nod], val);
    } else {
        int mid = (left + right) / 2;

        if (l <= mid) update(2 * nod, left, mid, l, r, val, t);
        if (mid < r) update(2 * nod + 1, mid + 1, right, l, r, val, t);
    }
}

ll query(int nod, int left, int right, int pos, bool t) {
    if (left == right) {
        return aint[t][nod];
    } else {
        int mid = (left + right) / 2;
        ll ans = aint[t][nod];

        if (pos <= mid) ans = min(ans, query(2 * nod, left, mid, pos, t));
        else ans = min(ans, query(2 * nod + 1, mid + 1, right, pos, t));

        return ans;
    }
}


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // int n;
    // cin >> n;
    // vector<int> a(n), c(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i] >> c[i];
    // }

    // vector<int> p(n);
    // iota(p.begin(), p.end(), 0);

    // do {
    //     if (p[0] != 0) {
    //         break;
    //     }

    //     int cur = 0;
    //     for (int i = 0; i < n; i++) {
    //         cur += max(c[p[i]], a[p[(i + 1) % n]] - a[p[i]]);
    //     }
    //     if (cur == 13) {
    //         for (int i = 0; i < n; i++) {
    //             cerr << p[i] + 1 << " ";
    //         }
    //         cerr << "\n";
    //     }

    // } while(next_permutation(p.begin(), p.end()));


    int n;
    cin >> n;
    vector<int> a(n + 1), c(n + 1);
    vector<pair<int, int>> vals;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        vals.push_back({a[i], c[i]});
    }
    sort(vals.begin(), vals.end());
    for (int i = 0; i < n; i++) {
        a[i + 1] = vals[i].first;
        c[i + 1] = vals[i].second;
    }

    ll sumC = 0;
    for (int i = 0; i < 2; i++) {
        fill(aint[i], aint[i] + 4 * MAXN, INF);
    }

    vector<ll> dp(n + 1, INF);
    update(1, 1, n, 1, 1, 0, 0);
    update(1, 1, n, 1, 1, -a[1], 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = min(query(1, 1, n, i, 0), query(1, 1, n, i, 1) + a[i]) + sumC;

        int res = i;
        for (int step = 1 << 18; step; step >>= 1) {
            if (res + step <= n && a[i] + c[i] >= a[res + step]) {
                res += step;
            }
        }

          /*
            dp[i] = min(max(a[i] - a[j] - c[j], 0) + dp[j] + c[j] - spC[j]) + spC[i - 1]

            dp[i] = min(max(c[j], a[i] - a[j]) + dp[j] - spC[j]) + spC[i - 1]

            dp[n] + c[n]
        */

        sumC += c[i];
        if (res != i) {
            ll cur = dp[i] - sumC + c[i];
            update(1, 1, n, i + 1, res, cur, 0);
        }
        if (res != n) {
            ll cur = dp[i] - sumC - a[i];
            update(1, 1, n, res + 1, n, cur, 1);
        }
    }

    cout << dp[n] + c[n];
    
    return 0;
}