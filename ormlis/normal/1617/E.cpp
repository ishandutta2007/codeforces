#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    map<int, map<int, pair<int, int>>> dp;
    rep(i, n) {
        int x; cin >> x;
        int t = 1;
        while(t < x) t *= 2;
        dp[x][-1] = {0, i};
        int r = 0;
        while(x > 0) {
            while(t / 2 >= x) t /= 2;
            x = t - x;
            r++;
            if (!dp[x].count(t)) {
                dp[x][t] = {r, i};
            } else {
                dp[x][t] = max(dp[x][t], {r, i});
            }
        }
    }
    int answer = -1;
    int ansx = -1, ansy = -1;
    for(auto &[vl, mp] : dp) {
        vector<pair<int, int>> can;
        for(auto &[x, y] : mp) {
            can.emplace_back(y.first, y.second);
        }
        sort(rall(can));
        if (can.size() <= 1) continue;
        int cur = can[0].first + can[1].first;
        if (cur <= answer) continue;
        answer = cur;
        ansx = can[0].second;
        ansy = can[1].second;
    }
    cout << ansx + 1 << ' ' << ansy + 1 << ' ' << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}