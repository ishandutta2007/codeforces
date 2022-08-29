#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
string compare;
int R;
vector<int> runs;

void output(const vector<int> &permutation) {
    for (int i = 0; i < N; i++)
        cout << permutation[i] << (i < N - 1 ? ' ' : '\n');
}

vector<int> solve_min() {
    vector<int> permutation;
    int current = N;
    bool first = true;

    for (int r = 0; r < R; r++) {
        if (runs[r] > 0) {
            int run = runs[r];

            if (first)
                run++;

            int start = current - run + 1;

            for (int i = start; i <= current; i++)
                permutation.push_back(i);

            current -= run;
        } else {
            int down = -runs[r];
            int up = r < R - 1 ? runs[r + 1] : 0;

            if (first)
                down++;

            for (int i = current - up; i >= current - up - (down - 1); i--)
                permutation.push_back(i);

            for (int i = current - up + 1; i <= current; i++)
                permutation.push_back(i);

            current -= down + up;
            r++;
        }

        first = false;
    }

    assert((int) permutation.size() == N);
    return permutation;
}

vector<int> solve_max() {
    vector<int> permutation;
    int current = 1;
    bool first = true;

    for (int r = 0; r < R; r++) {
        if (runs[r] > 0) {
            int up = runs[r];
            int down = r < R - 1 ? -runs[r + 1] : 0;

            if (first)
                up++;

            for (int i = current + down; i < current + down + up; i++)
                permutation.push_back(i);

            for (int i = current + down - 1; i >= current; i--)
                permutation.push_back(i);

            current += up + down;
            r++;
        } else {
            int down = -runs[r];

            if (first)
                down++;

            for (int i = current + down - 1; i >= current; i--)
                permutation.push_back(i);

            current += down;
        }

        first = false;
    }

    assert((int) permutation.size() == N);
    return permutation;
}

void run_case() {
    cin >> N >> compare;
    R = 0;
    runs = {};
    char previous = '?';
    int prev_count = 0;

    for (char c : compare)
        if (c == previous) {
            prev_count++;
        } else {
            if (prev_count > 0)
                runs.push_back(previous == '<' ? prev_count : -prev_count);

            previous = c;
            prev_count = 1;
        }

    if (prev_count > 0)
        runs.push_back(previous == '<' ? prev_count : -prev_count);

    R = runs.size();
    output(solve_min());
    output(solve_max());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}