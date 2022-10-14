#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;
string s;
lint memo[500005];
lint dp(lint n) {
    if (n == 1) return 1;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    lint res = 0;
    res += dp(n - 1);
    res %= MOD;
    res += dp(n - 2);
    res %= MOD;
    memo[n] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0 << "\n";
            return 0;
        }
    }

    vector<lint> A;
    for (int i = 0; i < s.size(); i++) {
        lint le = i;
        while ((s[i] == 'n' || s[i] == 'u') && i + 1 < s.size() && s[i + 1] == s[i]) i++;
        A.push_back(i - le + 1);
    }
    lint ans = 1;
    for (auto i : A) {
        ans *= dp(i);
        ans %= MOD;
    }
    cout << ans << "\n";

}