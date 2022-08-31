#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int get_ops(vector<int> current, vector<int> goal) {
    int n = current.size();
    map<int, int> goal_index;

    for (int i = 0; i < n; i++)
        goal_index[goal[i]] = i;

    vector<int> matches(n, 0);

    for (int i = 0; i < n; i++)
        if (goal_index.find(current[i]) != goal_index.end()) {
            int shift = (i - goal_index[current[i]] + n) % n;
            matches[shift]++;
        }

    int best = n;

    for (int i = 0; i < n; i++)
        best = min(best, i + n - matches[i]);

    return best;
}

int N, M;
vector<vector<int>> columns;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    columns.assign(M, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> columns[j][i];

    int total = 0;

    for (int c = 0; c < M; c++) {
        vector<int> goal(N);

        for (int i = 0; i < N; i++)
            goal[i] = i * M + c + 1;

        total += get_ops(columns[c], goal);
    }

    cout << total << '\n';
}