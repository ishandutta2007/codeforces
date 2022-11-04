#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto &x, const auto &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto &x, const auto &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

const int C = (int) 1e6 + 123;
const int MOD = (int) 1e9 + 7;

ll p2[C];
int cnt[C];
ll dp[C];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    p2[0] = 1;
    for (int i = 1; i < C; i++) {
        p2[i] = (p2[i - 1] * 2) % MOD;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 2; i < C; i++) {
        for (int j = i + i; j < C; j += i) {
            cnt[i] += cnt[j];
        }
    }

    ll answer = 0;

    for (int i = C - 1; i >= 2; i--) {
        if (cnt[i] == 0) {
            continue;
        }

        dp[i] = cnt[i] * p2[cnt[i] - 1] % MOD;
        for (int j = i + i; j < C; j += i) {
            dp[i] -= dp[j];
        }
        dp[i] = (dp[i] % MOD + MOD) % MOD;
        answer += dp[i] * i % MOD;
    }

    cout << answer % MOD << "\n";

    return 0;
}