#include <bits/stdc++.h>

using namespace std;


using ll = long long;


const ll mod = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        p >>= 1;
    }
    return res;
}

const int N = 3000;

int a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    ll g0, q, w, z;
    cin >> g0 >> q >> w >> z;
    a[0][0] = g0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j == 0) {
                continue;
            }
            g0 = (g0 * q + w) % z;
            a[i][j] = g0;
        }
    }
    for (int i = 0; i < n; ++i) {
        deque<pair<int, int>> q;
        for (int j = 0; j < m; ++j) {
            while (!q.empty() && q.back().first >= a[i][j]) {
                q.pop_back();
            }
            q.push_back({ a[i][j], j });
            a[i][j] = q.front().first;
            while (!q.empty() && q.front().second + y - 1 <= j) {
                q.pop_front();
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        deque<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && q.back().first >= a[i][j]) {
                q.pop_back();
            }
            q.push_back({ a[i][j], i });
            a[i][j] = q.front().first;
            while (!q.empty() && q.front().second + x - 1 <= i) {
                q.pop_front();
            }
        }
    }
    ll ans = 0;
    for (int i = x - 1; i < n; ++i) {
        for (int j = y - 1; j < m; ++j) {
            ans += a[i][j];
        }
    }
    cout << ans;
    return 0;
}