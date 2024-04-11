#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int INF = 1e8;

string s, t;
int memo[205][205][805];

int dp(int n, int m, int cnt) {
    if (cnt < 0 || cnt >= s.size() + t.size()) {
        return 1e8;
    }
    if (n == s.size() && m == t.size() && cnt >= 0) {
        return cnt;
    }
    if (n > s.size() || m > t.size()) {
        return 1e8;
    }
    if (memo[n][m][cnt] != -1) {
        return memo[n][m][cnt];
    }
    int res = 1e8;
    res = min(res, 1 + dp(n, m, cnt + 1));
    if (n < s.size() && m < t.size() && s[n] == t[m]) {
        res = min(res, 1 + dp(n + 1, m + 1, cnt + (s[n] == '(' ? 1 : -1)));
    } else {
        if (m < t.size()) res = min(res, 1 + dp(n, m + 1, cnt + (t[m] == '(' ? 1 : -1)));
        if (n < s.size()) res = min(res, 1 + dp(n + 1, m, cnt + (s[n] == '(' ? 1 : -1)));
    }

    return memo[n][m][cnt] = res;
}

string ans;

void backtrack(int n, int m, int cnt) {
    if (n == s.size() && m == t.size() && cnt >= 0) {
        for (int i = 0; i < cnt; i++) {
            ans.push_back(')');
        }
        return;
    }
    int res = dp(n, m, cnt);
    if(res == 1 + dp(n, m, cnt + 1)) {
        ans.push_back('(');
        backtrack(n, m, cnt + 1);
        return;
    }

    if (n < s.size() && m < t.size() && s[n] == t[m]) {
        if (res == 1 + dp(n + 1, m + 1, cnt + (s[n] == '(' ? 1 : -1))) {
            ans.push_back(s[n]);
            backtrack(n + 1, m + 1, cnt + (s[n] == '(' ? 1 : -1));
            return;
        }
    } else {
        if (m < t.size() && res == 1 + dp(n, m + 1, cnt + (t[m] == '(' ? 1 : -1))) {
            ans.push_back(t[m]);
            backtrack(n, m + 1, cnt + (t[m] == '(' ? 1 : -1));
            return;
        }
        if (n < s.size() && res == 1 + dp(n + 1, m, cnt + (s[n] == '(' ? 1 : -1))) {
            ans.push_back(s[n]);
            backtrack(n + 1, m, cnt + (s[n] == '(' ? 1 : -1));
            return;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(memo, -1, sizeof(memo));
    
    cin >> s >> t;
    dp(0, 0, 0);
    backtrack(0, 0, 0);
    // cout << dp(0, 0, 0) << "\n";
    cout << ans << "\n";
    return 0;
}

/*
5
2 1 2 1 1


*/