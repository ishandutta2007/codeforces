#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int m, cur, cnt[10];

int dp[10][10][2];
vector<int> num;

int recurse(int pos, int c, int f) {
    if (pos == num.size()) {
        return c == cur;
    }

    if (dp[pos][c][f] != -1)
        return dp[pos][c][f];

    int ans = 0;
    int limit = 9;
    if (!f) limit = num[pos];

    for (int i = 0; i <= limit; i++) {
        ans += recurse(pos + 1, c + (i == 4 or i == 7), i < num[pos] ? 1 : f);
    }
    return dp[pos][c][f] = ans;
}

ll dfs(int pos, int sum) {
    if (pos == 7) {
        return cur > sum;
    } else {
        ll ans = 0;
        for (int i = 0; i <= 9; i++) {
            if (cnt[i] == 0) continue;
            cnt[i]--;
            ans = (ans + (cnt[i] + 1) * dfs(pos + 1, sum + i)) % mod;
            cnt[i]++;
        }
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;

    int temp = m;
    while (temp) {
        num.push_back(temp % 10);
        temp /= 10;
    }
    reverse(num.begin(), num.end());

    for (int i = 0; i <= 9; i++) {
        memset(dp, -1, sizeof(dp));
        cur = i;
        cnt[i] = recurse(0, 0, 0);
    }

    cnt[0]--;

    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        if (!cnt[i]) break;
        cur = i;
        cnt[i]--;
        ans = (ans + (cnt[i] + 1) * dfs(1, 0)) % mod;
        cnt[i]++;
    }

    cout << ans << "\n";
    return 0;
}