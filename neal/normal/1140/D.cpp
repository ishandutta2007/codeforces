#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 505;
const long long LL_INF = (long long) 2e18 + 5;

int N;
long long dp[N_MAX][N_MAX];

int after(int x) {
    return x == N ? 1 : x + 1;
}

long long solve(int start, int end) {
    if (start == end || after(start) == end)
        return 0;

    long long &answer = dp[start][end];

    if (answer >= 0)
        return answer;

    answer = LL_INF;

    for (int i = after(start); i != end; i = after(i))
        answer = min(answer, solve(start, i) + solve(i, end) + start * end * i);

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> N;
    long long best = LL_INF;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            for (int k = j + 1; k <= N; k++)
                best = min(best, solve(i, j) + solve(j, k) + solve(k, i) + i * j * k);

    cout << best << '\n';
}