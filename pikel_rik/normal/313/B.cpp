#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    string s;
    cin >> s;

    int dp[s.length() + 1];
    dp[0] = 0;
    dp[1] = 0;

    if (s[0] == s[1])
        dp[1] = 1;

    int q;
    cin >> q;

    for (int i = 2; i < s.length(); i++){
        if (s[i-1] == s[i])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = dp[i-1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << dp[r-1] - dp[l-1] << "\n";
    }

    return 0;
}