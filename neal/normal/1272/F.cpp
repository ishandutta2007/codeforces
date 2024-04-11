#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}

const int NM_MAX = 201;
const int LEVEL_MAX = NM_MAX;
const int16_t INF16 = 15005;

struct compressed_dp {
    int16_t initial;
    bitset<LEVEL_MAX - 1> changes;

    int get(int index) const {
        int ones = (changes << (LEVEL_MAX - 1 - index)).count();
        return initial + ones - (index - ones);
    }

    void set(int16_t *dp) {
        initial = dp[0];

        for (int i = 0; i < LEVEL_MAX - 1; i++)
            changes[i] = dp[i + 1] - dp[i] > 0;
    }
};

int N, M;
string S, T;
int16_t dp_window[2][NM_MAX][LEVEL_MAX];
compressed_dp dp[NM_MAX][NM_MAX];

int main() {
    memset(dp_window, 63, sizeof(dp_window));
    cin >> S >> T;
    N = S.size();
    M = T.size();
    dp_window[0][0][0] = 0;

    for (int n = 0; n <= N; n++) {
        for (int m = 0; m <= M; m++) {
            int16_t *row = dp_window[0][m];
            int16_t minimum = INF16;

            for (int i = 0; i < LEVEL_MAX; i++) {
                minimize(row[i], minimum + i);
                minimize(minimum, row[i] - i);
            }

            minimum = INF16;

            for (int i = LEVEL_MAX - 1; i >= 0; i--) {
                minimize(row[i], minimum - i);
                minimize(minimum, row[i] + i);
            }

            dp[n][m].set(row);

            for (int i = 0; i < LEVEL_MAX; i++) {
                if (i < LEVEL_MAX - 1) {
                    int new_n_window = n < N && S[n] == '(' ? 1 : 0;
                    int new_m = m + (m < M && T[m] == '(' ? 1 : 0);
                    minimize(dp_window[new_n_window][new_m][i + 1], row[i] + 1);
                }

                if (i > 0) {
                    int new_n_window = n < N && S[n] == ')' ? 1 : 0;
                    int new_m = m + (m < M && T[m] == ')' ? 1 : 0);
                    minimize(dp_window[new_n_window][new_m][i - 1], row[i] + 1);
                }
            }
        }

        memcpy(dp_window[0], dp_window[1], sizeof(dp_window[0]));
        memset(dp_window[1], 63, sizeof(dp_window[1]));
    }

    cerr << dp[N][M].get(0) << endl;
    int n = N, m = M, level = 0;
    string answer;

    while (n > 0 || m > 0 || level > 0) {
        for (int n_change = 0; n_change <= 1; n_change++)
            for (int m_change = 0; m_change <= 1; m_change++)
                for (int paren = 0; paren <= 1; paren++) {
                    int new_n = n - n_change;
                    int new_m = m - m_change;
                    int level_change = 2 * paren - 1;

                    if (new_n < 0 || new_m < 0 || level + level_change < 0 || level + level_change >= LEVEL_MAX)
                        continue;

                    if (n_change == 1 && paren != (S[new_n] == '(' ? 0 : 1))
                        continue;

                    if (m_change == 1 && paren != (T[new_m] == '(' ? 0 : 1))
                        continue;

                    if (dp[n][m].get(level) != dp[new_n][new_m].get(level + level_change) + 1)
                        continue;

                    answer += paren == 0 ? '(' : ')';
                    n = new_n;
                    m = new_m;
                    level += level_change;
                    goto next_char;
                }

        next_char: ;
    }

    reverse(answer.begin(), answer.end());
    cout << answer << '\n';
}