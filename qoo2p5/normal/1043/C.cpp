#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

// Solution

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

const int N = 1005;

string s;
string dp[N][2]; // 0 -- min, 1 -- max
int from[N][2];

void run() {
    cin >> s;
    int n = (int) s.size();
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        dp[i][0] = dp[i - 1][0] + c;
        if (mini(dp[i][0], rev(dp[i - 1][1] + c))) {
            from[i][0] = 1;
        }
        dp[i][1] = dp[i - 1][1] + c;
        if (maxi(dp[i][1], rev(dp[i - 1][0] + c))) {
            from[i][1] = 1;
        }
    }

    cerr << dp[n][0] << "\n";
    string result;
    int cur_i = n;
    int cur_j = 0;
    while (cur_i > 0) {
        if (from[cur_i][cur_j]) {
            result += "1";
            cur_j = !cur_j;
        } else {
            result += "0";
        }
        cur_i--;
    }
    reverse(result.begin(), result.end());
    for (char c : result) {
        cout << c << " ";
    }
    cout << "\n";
}