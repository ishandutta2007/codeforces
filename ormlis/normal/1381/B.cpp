#include <bits/stdc++.h>
#include <cstdio>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<int> p(2 * n);
    range(i, n * 2) cin >> p[i];
    vector<int> a;
    for (int i = 0, j = 1; i < n * 2; i = j, j++) {
        while (j < n * 2 && p[j] < p[i]) j++;
        a.push_back(j - i);
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (auto &x: a) {
        vector<int> newdp(n + 1);
        range(i, n + 1) {
            if (i >= x && dp[i - x]) {
                newdp[i] = 1;
            }
            if (dp[i]) newdp[i] = 1;
        }
        dp = newdp;
    }
    if (dp[n]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}