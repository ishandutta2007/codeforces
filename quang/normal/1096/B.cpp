#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "Q" + s;
    int pref = 0, suff = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[1]) pref++;
        else break;
    }
    for (int i = n; i; i--) {
        if (s[i] == s[n]) suff++;
        else break;
    }
    long long res = 1;
    res += pref;
    res += suff;
    if (s[1] == s[n]) {
        res += 1ll * pref * suff;
    }
    cout << res % MOD << endl;
    return 0;
}