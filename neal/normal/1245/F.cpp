#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int BITS = 30;

int A, B;
long long dp[BITS][2][2];

long long solve(int bit = BITS - 1, bool a_matches = true, bool b_matches = true) {
    if (A < 0 || B < 0)
        return 0;

    if (bit < 0)
        return 1;

    long long &answer = dp[bit][a_matches][b_matches];

    if (answer >= 0)
        return answer;

    answer = 0;

    for (int a = 0; a < 2; a++)
        for (int b = 0; a + b < 2; b++) {
            if (a_matches && (A >> bit & 1) == 0 && a == 1)
                continue;

            if (b_matches && (B >> bit & 1) == 0 && b == 1)
                continue;

            answer += solve(bit - 1, a_matches && (A >> bit & 1) == a, b_matches && (B >> bit & 1) == b);
        }

    return answer;
}

void solve_case() {
    int L, R;
    cin >> L >> R;

    long long answer = 0;

    A = B = R;
    memset(dp, -1, sizeof(dp));
    answer += solve();

    A = L - 1;
    memset(dp, -1, sizeof(dp));
    answer -= 2 * solve();

    B = L - 1;
    memset(dp, -1, sizeof(dp));
    answer += solve();

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}