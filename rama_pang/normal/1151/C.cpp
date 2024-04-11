#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint MOD = 1e9 + 7;

lint solve(lint n) {
    if (n == 0) {
        return 0;
    }
    lint res = 0;
    
    vector<pair<lint, lint>> interval;
    lint cur = 1, mult = 2;
    interval.emplace_back(1, 1);
    while (cur <= n) {
        interval.emplace_back(cur + 1, cur + mult);
        cur += mult;
        mult *= 2;
    }
    if (interval.back().second > n) {
        interval.back().second = n;
    }

    lint odd = 0, even = 0;
    for (int i = 0; i < interval.size(); i++) {
        if (i % 2 == 0) { // add odd
            lint new_odd = (odd + interval[i].second - interval[i].first + 1) % MOD;
            res += ((new_odd * new_odd) % MOD) - ((odd * odd) % MOD);
            res %= MOD;
            odd = new_odd % MOD;
        } else { // add even
            lint new_even = (even + interval[i].second - interval[i].first + 1) % MOD;
            res += ((new_even * (new_even + 1)) % MOD) - ((even * (even + 1)) % MOD);
            even = new_even % MOD;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint L, R;
    cin >> L >> R;
    lint ans = solve(R) - solve(L - 1);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << "\n";
}