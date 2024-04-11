#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int bal = 0;
    int minbal = 0;
    range(i, n) {
        if (s[i] == '(') bal++;
        else bal--;
        minbal = min(minbal, bal);
    }
    if (bal != 0) {
        cout << "0\n1 1";
        return;
    }
    int sdvig = 0;
    range(i, n) {
        if (s[i] == '(') bal++;
        else bal--;
        if (bal == minbal) {
            sdvig = i + 1;
            s = s.substr(i + 1, n) + s.substr(0, i);
            break;
        }
    }

    vector<int> balance(n + 1);
    bal = 0;
    range(i, n) {
        balance[i] = bal;
        if (s[i] == '(') bal++;
        else bal--;
    }

    int cnt_zero = 0;
    range(i, n) if (balance[i] == 0) cnt_zero++;

    ar<int, 3> ans = {cnt_zero, 0, 0};
    vector<int> dp(n), dp2(n);
    int max_i_zero = 0, max_i_one = 0;
    for(int i = 1; i < n; ++i) {
        dp[i] = dp[i-1];
        dp2[i] = dp2[i-1];
        if (balance[i] == 0) {
            max_i_zero = max_i_one = i;
        } else if (balance[i] == 1) {
            dp[i]++;
            max_i_one = i;
        } else if (balance[i] == 2) {
            dp2[i]++;
        }
        if (s[i] == '(') {
            if (s[max_i_one] != '(') max_i_one = i;
            if (s[max_i_zero] != '(') max_i_zero = i;
        } else {
            ans = max(ans, {dp[i] - dp[max_i_zero], max_i_zero, i});
            ans = max(ans, {dp2[i] - dp2[max_i_one] + cnt_zero, max_i_one, i});
        }
    }
    cout << ans[0] << "\n" << (ans[1] + sdvig) % n + 1 << " " << (ans[2] + sdvig) % n + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}