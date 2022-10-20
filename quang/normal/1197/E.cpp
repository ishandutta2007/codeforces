#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
int in[N], out[N];
vector<int> vals;
pair<int, int> dp[N * 2];
vector<int> events[N * 2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vals.push_back(0);
    int maxIn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> out[i] >> in[i];
        vals.push_back(in[i]);
        vals.push_back(out[i]);
        maxIn = max(maxIn, in[i]);
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(vals.begin(), vals.end(), out[i]) - vals.begin();
        events[pos].push_back(in[i]);
    }
    pair<int, int> res = {MOD, 1};
    dp[0] = {0, 1};
    for (int i = 1; i < vals.size(); i++) {
        dp[i] = {MOD, 1};
        if (dp[i].first > dp[i - 1].first + vals[i] - vals[i - 1]) {
            dp[i] = {dp[i - 1].first + vals[i] - vals[i - 1], dp[i - 1].second};
        } else if (dp[i].first == dp[i - 1].first) {
            dp[i].second = add(dp[i].second, dp[i - 1].second);
        }
        //from events
        for (int u : events[i]) {
            int pos = lower_bound(vals.begin(), vals.end(), u) - vals.begin();
            if (dp[i].first > dp[pos].first) {
                dp[i] = dp[pos];
            } else if (dp[i].first == dp[pos].first) {
                dp[i].second = add(dp[i].second, dp[pos].second);
            }
        }
        if (vals[i] > maxIn) {
            if (res.first > dp[i].first) {
                res = dp[i];
            } else if (res.first == dp[i].first) {
                res.second = add(res.second, dp[i].second);
            }
        }
    }
    cout << res.second << endl;
    return 0;
}