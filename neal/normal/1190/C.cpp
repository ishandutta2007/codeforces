#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string PERSON[3] = {"tokitsukaze", "quailty", "once again"};
const int INF = 1e9 + 5;

void winner(int who) {
    assert(0 <= who && who < 3);
    cout << PERSON[who] << '\n';
    exit(0);
}

const int N_MAX = 1e5 + 5;

int N, K;
string cards;
int prefix_min[2][N_MAX], prefix_max[2][N_MAX];
int suffix_min[2][N_MAX], suffix_max[2][N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> cards;

    prefix_min[0][0] = prefix_min[1][0] = INF;
    prefix_max[0][0] = prefix_max[1][0] = -INF;

    for (int i = 0; i < N; i++) {
        int card = cards[i] - '0';
        int other = 1 - card;
        prefix_min[card][i + 1] = min(prefix_min[card][i], i);
        prefix_max[card][i + 1] = max(prefix_max[card][i], i);
        prefix_min[other][i + 1] = prefix_min[other][i];
        prefix_max[other][i + 1] = prefix_max[other][i];
    }

    suffix_min[0][N] = suffix_min[1][N] = INF;
    suffix_max[0][N] = suffix_max[1][N] = -INF;

    for (int i = N - 1; i >= 0; i--) {
        int card = cards[i] - '0';
        int other = 1 - card;
        suffix_min[card][i] = min(suffix_min[card][i + 1], i);
        suffix_max[card][i] = max(suffix_max[card][i + 1], i);
        suffix_min[other][i] = suffix_min[other][i + 1];
        suffix_max[other][i] = suffix_max[other][i + 1];
    }

    // Check if we can win in one move.
    if (prefix_max[0][N] - prefix_min[0][N] < K || prefix_max[1][N] - prefix_min[1][N] < K)
        winner(0);

    // Check if we can prevent a win on the second move.
    bool prevent_win = false;

    for (int i = 0; i + K <= N; i++)
        for (int color = 0; color < 2; color++) {
            int other = 1 - color;
            int end = i + K - 1;

            int my_min = min(prefix_min[color][i], i);
            int my_max = max(suffix_max[color][end + 1], end);

            int other_min = min(prefix_min[other][i], suffix_min[other][end + 1]);
            int other_max = max(prefix_max[other][i], suffix_max[other][end + 1]);

            if (my_max - my_min >= K && other_max - other_min >= K)
                prevent_win = true;
        }

    if (prevent_win)
        winner(2);
    else
        winner(1);
}