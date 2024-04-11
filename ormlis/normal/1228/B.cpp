#include <bits/stdc++.h>
#include <unordered_set>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

int g[1001][1001];
ll mod = 1e9 + 7;
ll binpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2) {
        return binpow(a, b - 1) * a % mod;
    }
    ll m = binpow(a, b / 2);
    return m * m % mod;
}

void solve() {
    int h, w; cin >> h >> w;
    range(i, h) {
        memset(g[i], -1, sizeof(g[i]));
        int r; cin >> r;
        range(j, r) {
            g[i][j] = 1;
        }
        g[i][r] = 0;
    }
    range(i, w) {
        int c; cin >> c;
        range(j, c) {
            if (g[j][i] == 0) {
                cout << 0;
                return;
            }
            g[j][i] = 1;
        }
        if (g[c][i] == 1) {
            cout << 0;
            return;
        }
        g[c][i] = 0;
    }
    ll ans = 0;
    range(i, h) {
        range(j, w) {
            if (g[i][j] == -1) {
                ans += 1;
            }
        }
    }
    cout << binpow(2, ans) << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}