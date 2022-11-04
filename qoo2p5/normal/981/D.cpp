#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

auto mini(auto &x, const auto &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}

auto maxi(auto &x, const auto &y) {
    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

const int N = 61;

int n, k;
ll a[N];
bool dp[N][N];

bool can(ll mask) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    rep(i, 1, n + 1) {
        rep(j, 1, k + 1) {
            ll s = 0;
            per(t, i, 1) {
                s += a[t];
                if ((s & mask) == mask) {
                    dp[i][j] |= dp[t - 1][j - 1];
                }
            }
        }
    }
    return dp[n][k];
}

void run() {
    cin >> n >> k;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    ll ans = 0;
    per(bit, N - 1, 0) {
        if (can(ans | (1LL << bit))) {
            ans |= (1LL << bit);
        }
    }
    cout << ans << "\n";
}