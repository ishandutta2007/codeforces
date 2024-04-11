#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int N, M, K, Q;
vector<pair<int, int>> treasures;
vector<int> safe;

template<typename T_key, typename T_value>
void improve_map(map<T_key, T_value> &options, T_key key, T_value value) {
    if (options.find(key) == options.end() || value < options[key])
        options[key] = value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> Q;
    treasures.resize(K);

    for (pair<int, int> &t : treasures)
        cin >> t.first >> t.second;

    treasures.emplace_back(1, 1);
    K++;
    sort(treasures.begin(), treasures.end());
    safe.resize(Q);

    for (int &s : safe)
        cin >> s;

    sort(safe.begin(), safe.end());
    map<int, long long> col_options;
    col_options[1] = 0;
    int current_row = 1;
    long long answer = LL_INF;

    for (int i = 0, j = 0; i < K; i = j) {
        while (j < K && treasures[i].first == treasures[j].first)
            j++;

        int row = treasures[i].first;
        int left_col = treasures[i].second, right_col = treasures[j - 1].second;

        for (auto &op : col_options)
            op.second += row - current_row;

        current_row = row;
        map<int, long long> minimums;

        for (auto &op : col_options) {
            improve_map(minimums, left_col, op.second + abs(op.first - right_col) + abs(right_col - left_col));
            improve_map(minimums, right_col, op.second + abs(op.first - left_col) + abs(left_col - right_col));
        }

        answer = min(minimums[left_col], minimums[right_col]);
        col_options.clear();

        for (auto &mn : minimums) {
            int safe_index = lower_bound(safe.begin(), safe.end(), mn.first) - safe.begin();
            improve_map(col_options, safe[safe_index], mn.second + abs(mn.first - safe[safe_index]));

            if (safe_index > 0) {
                safe_index--;
                improve_map(col_options, safe[safe_index], mn.second + abs(mn.first - safe[safe_index]));
            }
        }
    }

    cout << answer << '\n';
}