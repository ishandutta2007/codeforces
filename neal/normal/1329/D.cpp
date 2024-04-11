#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET = 26;
const char MIN_CHAR = 'a';

vector<int> eq_count;

int needed() {
    int maximum = 0, sum = 0;

    for (int c = 0; c < ALPHABET; c++) {
        maximum = max(maximum, eq_count[c]);
        sum += eq_count[c];
    }

    return max(maximum, (sum + 1) / 2) + 1;
}

bool match(int x, int y) {
    if (x == y) return false;

    int before = needed();
    eq_count[x]--;
    eq_count[y]--;
    int after = needed();

    if (after == before - 1)
        return true;

    eq_count[x]++;
    eq_count[y]++;
    return false;
}

void run_case() {
    eq_count.assign(ALPHABET, 0);

    string S;
    cin >> S;

    for (char &c : S)
        c -= MIN_CHAR;

    int N = S.size();

    for (int i = 0; i < N - 1; i++)
        if (S[i] == S[i + 1])
            eq_count[S[i]]++;

    vector<pair<int, int>> moves;
    vector<pair<int, char>> eq_stack;
    int removed = 0;

    for (int i = 0; i < N - 1; i++)
        if (S[i] == S[i + 1]) {
            if (!eq_stack.empty() && match(eq_stack.back().second, S[i])) {
                moves.emplace_back(eq_stack.back().first + 1, i + 1 - removed);
                eq_stack.pop_back();
                removed += moves.back().second - moves.back().first;
            } else {
                eq_stack.emplace_back(i - removed, S[i]);
            }
        }

    while (!eq_stack.empty()) {
        moves.emplace_back(eq_stack.back().first + 1, N - removed);
        removed += moves.back().second - moves.back().first;
        eq_stack.pop_back();
    }

    moves.emplace_back(0, N - removed);
    cout << moves.size() << '\n';

    for (pair<int, int> &move : moves)
        cout << move.first + 1 << ' ' << move.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}