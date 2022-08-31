#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
void minimize(T1 &a, const T2 &b) {
    if (b < a)
        a = b;
}

const int N_MAX = 505;

int N;
string S;
int16_t dp[N_MAX][N_MAX];

int main() {
    cin >> N >> S;
    N = unique(S.begin(), S.end()) - S.begin();

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j <= N; j++)
            dp[i][j] = dp[i + 1][j] + 1;

        for (int k = i + 1; k < N; k++)
            if (S[i] == S[k])
                for (int j = k + 1; j <= N; j++)
                    minimize(dp[i][j], dp[i + 1][k] + dp[k][j]);
    }

    cout << dp[0][N] << '\n';
}