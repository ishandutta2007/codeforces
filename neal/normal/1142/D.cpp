#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 1e5 + 5;

int TABLE[11][11];

int N;
string S;
int dp[11][11][N_MAX];

int how_far(int row, int col, int index) {
    int &answer = dp[row][col][index];

    if (answer >= 0)
        return answer;

    if (index >= N)
        return 0;

    row = TABLE[row][col];
    col = S[index] - '0';

    if (row <= col)
        return 0;

    return answer = 1 + how_far(row, col, index + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 10;

    for (int row = 0; row <= 10; row++)
        for (int col = 0; col < row; col++) {
            TABLE[row][col] = num;
            num = (num + 1) % 11;
        }

    cin >> S;
    N = S.size();
    long long total = N;

    for (int i = 0; i < N; i++)
        if (S[i] == '0')
            total--;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i + 1 < N; i++) {
        int row = S[i] - '0', col = S[i + 1] - '0';

        if (row <= col)
            continue;

        total++;
        total += how_far(row, col, i + 2);
    }

    cout << total << '\n';
}