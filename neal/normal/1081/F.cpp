#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, T;

int query(int L, int R) {
    assert(1 <= L && L <= R && R <= N);
    cout << "? " << L << ' ' << R << endl;
    int t;
    cin >> t;

    if (t == -1)
        exit(0);

    T = t;
    return t;
}

int guaranteed_flip(int L, int R, int which = 0, bool check = true) {
    if (check)
        assert(R % 2 != (N - L + 1) % 2);

    int goal_parity_change = R % 2;
    int left_flips = 0, right_flips = 0;

    while (true) {
        int start_T = T;
        int result = query(L, R);

        if ((start_T + goal_parity_change) % 2 == result % 2)
            left_flips++;
        else
            right_flips++;

        if (which == 0 && left_flips % 2 == 1 && right_flips % 2 == 0)
            return result;

        if (which == 1 && left_flips % 2 == 0 && right_flips % 2 == 1)
            return result;
    }
}

vector<int> original;

void output() {
    cout << "! ";

    for (int i = 1; i <= N; i++)
        cout << original[i];

    cout << endl;
}

void solve_original(int first_element, vector<bool> &same) {
    int current;

    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            current = first_element;
        } else {
            current = same[i - 1] ? current : 1 - current;
        }

        original[i] = current;
    }
}

int main() {
    cin >> N >> T;

    if (N == 1) {
        original = {0, T};
        output();
        return 0;
    }

    original.assign(N + 1, -1);

    if (N % 2 == 0) {
        int running_count = 0;

        for (int i = 1; i <= N; i++) {
            int start_T = T;
            int left_flip_change = (i - 1) - 2 * running_count;
            original[i] = guaranteed_flip(i, i) > start_T + left_flip_change ? 0 : 1;
            running_count += original[i];
            guaranteed_flip(i, i);
        }

        output();
        return 0;
    }

    vector<int> saved_changes(N + 1, 0);
    vector<bool> same(N + 1, false);

    for (int i = 1; i < N; i += 2) {
        int expected_change = i == 1 ? 0 : saved_changes[i - 2];
        int start_T = T;
        saved_changes[i] = guaranteed_flip(i, i + 1) - start_T;
        same[i] = saved_changes[i] != expected_change;
        guaranteed_flip(i, i + 1);
    }

    for (int i = N - 1; i > 1; i -= 2) {
        int expected_change = i == N - 1 ? 0 : saved_changes[i + 2];
        int start_T = T;
        saved_changes[i] = guaranteed_flip(i, i + 1, 1) - start_T;
        same[i] = saved_changes[i] != expected_change;
        guaranteed_flip(i, i + 1, 1);
    }

    int same_as_first = 1;
    bool current = true;

    for (int i = 1; i < N; i++) {
        if (!same[i])
            current = !current;

        if (current)
            same_as_first++;
    }

    solve_original(same_as_first > N / 2 ^ T > N / 2 ? 0 : 1, same);
    output();
}