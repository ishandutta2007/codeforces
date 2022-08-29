#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INTERESTING = 3;

int N;
string S;
vector<int> levels;
vector<vector<int>> counts;

int get_min(int start, int end) {
    for (int c = 0; c < INTERESTING; c++)
        if (counts[c][end] - counts[c][start] > 0)
            return c;

    return INTERESTING;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    levels.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        levels[i + 1] = levels[i] + (S[i] == '(' ? +1 : -1);

    if (levels[N] != 0) {
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }

    int minimum = *min_element(levels.begin(), levels.end());

    for (int i = 1; i <= N; i++)
        levels.push_back(levels[i]);

    for (int i = 0; i < N; i++)
        S.push_back(S[i]);

    counts.assign(INTERESTING, {});

    for (int c = 0; c < INTERESTING; c++) {
        counts[c].assign(2 * N + 2, 0);

        for (int i = 0; i <= 2 * N; i++)
            counts[c][i + 1] = counts[c][i] + (levels[i] == minimum + c ? 1 : 0);
    }

    // some min + 2 -> -2
    // some min + 1 -> -2 (must outnumber the actual min)

    // all min -> +2 is covered by the above case after concatenating
    // (any min -> -2 doesn't make sense)

    int best = count(levels.begin(), levels.begin() + N, minimum);
    int best_first = 0, best_second = 0;

    for (int target = 1; target <= 2; target++)
        for (int i = 1, j = 1; i <= N; i++) {
            while (get_min(i, j + 1) >= target)
                j++;

            if (S[i - 1] == '(' && j > i) {
                assert(S[j - 1] == ')');
                int my_min = get_min(i, j);
                int my_count = 0;
                assert(my_min >= target);

                if (my_min == 1)
                    my_count = counts[1][j] - counts[1][i];
                else if (my_min == 2)
                    my_count = counts[2][j] - counts[2][i] + counts[0][i + N] - counts[0][j];

                if (my_count > best) {
                    best = my_count;
                    best_first = i - 1;
                    best_second = j - 1;
                }
            }
        }

    cout << best << '\n';
    cout << best_first % N + 1 << ' ' << best_second % N + 1 << '\n';
}