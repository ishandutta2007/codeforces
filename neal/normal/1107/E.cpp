#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N_MAX = 205;

int N;
string S;
vector<long long> A;
long long dp[N_MAX][N_MAX][N_MAX];

long long solve(int start, int end, int prefix) {
    if (end - start <= 0)
        return 0;

    if (end - start == 1)
        return A[prefix];

    long long &answer = dp[start][end][prefix];

    if (answer != 0)
        return answer;

    answer = A[prefix] + solve(start + 1, end, 1);

    for (int i = start + 1; i < end; i++)
        if (S[i] == S[start])
            answer = max(answer, solve(start + 1, i, 1) + solve(i, end, prefix + 1));

    return answer;
}

int main() {
    cin >> N >> S;
    A.assign(N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cout << solve(0, N, 1) << '\n';
}