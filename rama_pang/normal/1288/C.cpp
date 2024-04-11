#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;
lint memo[11][1001][1001];
lint N, M;
lint dp(lint pos, lint lastA, lint lastB) {
    if (lastA > lastB) {
        return 0;
    }
    if (lastA > N) {
        return 0;
    }
    if (lastB < 1) {
        return 0;
    }
    if (pos == M) {
        return 1;
    }
    if (memo[pos][lastA][lastB] != -1) {
        return memo[pos][lastA][lastB];
    }
    lint res = 0;
    res += dp(pos, lastA + 1, lastB);
    res += dp(pos, lastA, lastB - 1);
    res -= dp(pos, lastA + 1, lastB - 1);
    res += dp(pos + 1, lastA, lastB);
    res %= MOD;
    if (res < 0) {
        res += MOD;
    }
    return memo[pos][lastA][lastB] = res;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> N >> M;
    cout << dp(0, 1, N) << "\n";

}