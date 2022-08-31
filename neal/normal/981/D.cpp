#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 56;

int N, K;
long long books[MAX];
bool dp[MAX][MAX];

bool possible(long long beauty) {
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++) {
            if (dp[i][k]) {
                long long sum = 0;

                for (int j = i; j < N; j++) {
                    sum += books[j];

                    if ((beauty & sum) == beauty) {
                        dp[j + 1][k + 1] = true;
                    }
                }
            }
        }
    }

    return dp[N][K];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> books[i];
    }

    long long goal = 0;

    for (int bit = MAX; bit >= 0; bit--) {
        goal |= 1LL << bit;

        if (!possible(goal)) {
            goal -= 1LL << bit;
        }
    }

    cout << goal << '\n';
    return 0;
}