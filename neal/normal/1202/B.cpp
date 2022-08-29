#include <algorithm>
#include <cassert>
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

const int INF = 1e9 + 5;

int solve(const string &S, int x, int y) {
    vector<int> cost(10, INF);

    for (int a = 0; a <= 10; a++)
        for (int b = 0; b <= 10; b++)
            if (a + b > 0)
                minimize(cost[(a * x + b * y) % 10], a + b);

    int total = 0;

    for (int i = 1; i < (int) S.size(); i++) {
        int diff = (S[i] - S[i - 1] + 10) % 10;
        total += cost[diff] - 1;

        if (total >= INF / 2)
            return -1;
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int answer[10][10];

    for (int x = 0; x < 10; x++)
        for (int y = x; y < 10; y++)
            answer[x][y] = answer[y][x] = solve(S, x, y);

    for (int x = 0; x < 10; x++)
        for (int y = 0; y < 10; y++)
            cout << answer[x][y] << (y < 9 ? ' ' : '\n');
}