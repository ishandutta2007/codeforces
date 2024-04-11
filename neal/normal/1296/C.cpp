#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

void run_case() {
    int N;
    string str;
    cin >> N >> str;
    vector<pair<int, int>> partial_sum(N + 1, {0, 0});

    for (int i = 0; i < N; i++) {
        int x = 0, y = 0;

        if (str[i] == 'L')
            x = -1;
        else if (str[i] == 'R')
            x = +1;
        else if (str[i] == 'U')
            y = +1;
        else if (str[i] == 'D')
            y = -1;
        else
            assert(false);

        partial_sum[i + 1] = {partial_sum[i].first + x, partial_sum[i].second + y};
    }

    int shortest = INF;
    int start = -1, end = -1;
    map<pair<int, int>, int> seen;

    for (int i = 0; i <= N; i++) {
        if (seen.count(partial_sum[i])) {
            int length = i - seen[partial_sum[i]];

            if (length < shortest) {
                shortest = length;
                start = seen[partial_sum[i]];
                end = i;
            }
        }

        seen[partial_sum[i]] = i;
    }

    if (shortest < INF) {
        cout << start + 1 << ' ' << end << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}