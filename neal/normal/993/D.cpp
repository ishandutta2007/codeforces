#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N_MAX = 55;
const int B_MAX = 105;
const int PROC_MAX = 5005;
const long long LL_INF = 1e18 + 5;

int N;
pair<int, int> task[N_MAX];
long long dp[N_MAX][PROC_MAX];
long long new_dp[N_MAX][PROC_MAX];

template<typename T>
void minimize(T &a, const T &b) {
    if (b < a)
        a = b;
}

long long div_round_up(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> task[i].first;

    for (int i = 0; i < N; i++)
        cin >> task[i].second;

    sort(task, task + N, greater<pair<int, int>>());
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && task[i].first == task[j].first)
            j++;

        memset(new_dp, 63, sizeof(new_dp));
        int count = j - i;

        for (int k = 0; k <= count; k++) {
            long long sum_power = 0;
            int new_procs = 0;

            for (int x = i; x < j - k; x++) {
                sum_power += task[x].first;
                new_procs += task[x].second;
            }

            for (int available = k; available <= N; available++)
                for (int procs = 0; procs < PROC_MAX; procs++)
                    if (dp[available][procs] < LL_INF)
                        minimize(new_dp[available + (count - k) - k][procs + new_procs], dp[available][procs] + sum_power);
        }

        memcpy(dp, new_dp, sizeof(dp));
    }

    long long best = LL_INF;

    for (int available = 0; available <= N; available++)
        for (int procs = 1; procs < PROC_MAX; procs++)
            if (dp[available][procs] < LL_INF)
                minimize(best, div_round_up(1000 * dp[available][procs], procs));

    cout << best << '\n';
    return 0;
}