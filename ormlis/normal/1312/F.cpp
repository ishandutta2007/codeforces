#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

int mex(const vector<int> &a) {
    range(j, (int) a.size() + 1) {
        bool f = false;
        for (auto &x: a) {
            if (x == j) {
                f = true;
                break;
            }
        }
        if (f) continue;
        return j;
    }
    return (int) a.size();
}

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    const int K = 500;
    vector<ar<int, 3>> dp(K);
    dp[0] = {0, 0, 0};
    // 50
    map<vector<ar<int, 3>>, int> states;
    vector<ar<int, 3>> current = {dp[0]};
    int sp = -1, lp = 0;
    for (int i = 1; i < K; ++i) {
        range(j, 3) {
            vector<int> a = {dp[max(i - x, 0)][0]};
            if (j != 1) a.push_back(dp[max(i - y, 0)][1]);
            if (j != 2) a.push_back(dp[max(i - z, 0)][2]);
            dp[i][j] = mex(a);
        }
        current.push_back(dp[i]);
        if (current.size() > 50) current.erase(current.begin());
        int j = i + 1 - (int) current.size();
        if (states.count(current)) {
            sp = states[current];
            lp = j - states[current];
            break;
        }
        states[current] = j;
    }
    vector<int> gnums(n);
    vector<ll> a(n);

    auto get_gnum = [&](ll x, int y) {
        if (x < sp) {
            return dp[x][y];
        }
        x -= sp;
        x %= lp;
        return dp[x + sp][y];
    };
    int xxo = 0;
    range(i, n) {
        cin >> a[i];
        gnums[i] = get_gnum(a[i], 0);
        xxo ^= gnums[i];
    }
    int cnt = 0;
    range(i, n) {
        xxo ^= gnums[i];
        int x1 = get_gnum(max(a[i] - x, 0ll), 0);
        int x2 = get_gnum(max(a[i] - y, 0ll), 1);
        int x3 = get_gnum(max(a[i] - z, 0ll), 2);
        if (xxo == x1) cnt++;
        if (xxo == x2) cnt++;
        if (xxo == x3) cnt++;
        xxo ^= gnums[i];
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}