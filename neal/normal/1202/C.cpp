#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T1, typename T2>
bool maximize(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}


int get_move(char c) {
    if (c == 'A')
        return -1;
    else if (c == 'D')
        return +1;
    else
        return 0;
}

pair<int, int> add_to_front_of_range(pair<int, int> range, int add) {
    range.first += add;
    range.second += add;
    minimize(range.first, 0);
    maximize(range.second, 0);
    return range;
}

pair<long long, bool> solve_horizontal(string S) {
    int N = S.size();
    vector<int> prefix_position(N + 1, 0);
    vector<pair<int, int>> prefix_range(N + 1, {0, 0});

    for (int i = 0; i < N; i++) {
        prefix_position[i + 1] = prefix_position[i] + get_move(S[i]);
        prefix_range[i + 1] = prefix_range[i];
        minimize(prefix_range[i + 1].first, prefix_position[i + 1]);
        maximize(prefix_range[i + 1].second, prefix_position[i + 1]);
    }

    vector<pair<int, int>> suffix_range(N + 1, {0, 0});

    for (int i = N - 1; i >= 0; i--)
        suffix_range[i] = add_to_front_of_range(suffix_range[i + 1], get_move(S[i]));

    long long width = prefix_range[N].second - prefix_range[N].first + 1;
    bool can_reduce = false;

    for (int i = 0; i <= N; i++)
        for (int add = -1; add <= +1; add++) {
            pair<int, int> before = prefix_range[i];
            pair<int, int> after = suffix_range[i];
            after = add_to_front_of_range(after, add);

            int position = prefix_position[i];
            minimize(before.first, position + after.first);
            maximize(before.second, position + after.second);

            long long range = before.second - before.first + 1;
            assert(abs(range - width) <= 1);
            can_reduce = can_reduce || range == width - 1;
        }

    return {width, can_reduce};
}

void run_case() {
    string S;
    cin >> S;
    pair<long long, bool> horizontal = solve_horizontal(S);

    for (char &c : S)
        if (c == 'W')
            c = 'D';
        else if (c == 'D')
            c = 'S';
        else if (c == 'S')
            c = 'A';
        else if (c == 'A')
            c = 'W';
        else
            assert(false);

    pair<long long, bool> vertical = solve_horizontal(S);
    long long answer = horizontal.first * vertical.first;

    if (horizontal.second)
        minimize(answer, (horizontal.first - 1) * vertical.first);

    if (vertical.second)
        minimize(answer, horizontal.first * (vertical.first - 1));

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}