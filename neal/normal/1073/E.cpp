#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 20;
const int MOD = 998244353;

int N, K;
vector<int> digits;
long long power10[N_MAX];
pair<long long, long long> dp[N_MAX][1 << 10][2];

// Returns {sum, count}
pair<long long, long long> solve(int position, int mask, bool match) {
    if (__builtin_popcount(mask) > K)
        return {0, 0};

    if (position < 0)
        return {0, 1};

    pair<long long, long long> &answer = dp[position][mask][match];

    if (answer.first != -1)
        return answer;

    long long sum = 0, count = 0;

    for (int d = (mask == 0 ? 1 : 0); d <= (match ? digits[position] : 9); d++) {
        pair<long long, long long> next = solve(position - 1, mask | 1 << d, match && d == digits[position]);
        count = (count + next.second) % MOD;
        sum = (sum + next.first + d * power10[position] * next.second) % MOD;
    }

    return answer = {sum, count};
}

long long compute(long long x) {
    if (x == 0)
        return 0;

    digits.clear();

    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }

    N = digits.size();
    power10[0] = 1;

    for (int i = 1; i <= N; i++)
        power10[i] = 10 * power10[i - 1] % MOD;

    memset(dp, -1, sizeof(dp));
    long long total = 0;

    for (int i = N - 1; i >= 0; i--)
        total = (total + solve(i, 0, i == N - 1).first) % MOD;

    return total;
}

int main() {
    long long L, R;
    cin >> L >> R >> K;
    cout << (compute(R) + MOD - compute(L - 1)) % MOD << '\n';
}