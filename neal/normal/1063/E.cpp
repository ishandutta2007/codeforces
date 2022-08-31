#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> goal(N);
    bool is_identity = true;

    for (int i = 0; i < N; i++) {
        cin >> goal[i];
        goal[i]--;
        is_identity = is_identity && goal[i] == i;
    }

    if (is_identity) {
        cout << N << '\n';

        for (int i = 0; i < N; i++)
            cout << string(N, '.') << '\n';

        return 0;
    }

    vector<bool> visited(N, false);
    vector<int> cycle_points;

    for (int i = 0; i < N; i++)
        if (goal[i] != i && !visited[i]) {
            cycle_points.push_back(i);

            for (int j = i; !visited[j]; j = goal[j])
                visited[j] = true;
        }

    assert(!cycle_points.empty());
    sort(cycle_points.begin(), cycle_points.end());
    vector<string> reverse_rows(N, string(N, '.'));

    if (cycle_points.size() > 1) {
        for (int i = (int) cycle_points.size() - 1; i >= 0; i--) {
            reverse_rows[0][cycle_points[i]] = '/';
            goal[cycle_points[i]] = i == 0 ? -1 : goal[cycle_points[i - 1]];
        }
    }

    int trash = cycle_points[0];

    for (int row = 1; row < N; row++) {
        int to_trash = -1;

        for (int i = 0; i < N; i++)
            if (goal[i] == trash)
                to_trash = i;

        if (to_trash == -1)
            break;

        swap(goal[trash], goal[to_trash]);
        reverse_rows[row][trash] = reverse_rows[row][to_trash] = to_trash < trash ? '/' : '\\';
        trash = to_trash;
    }

    cout << N - 1 << '\n';

    for (int i = N - 1; i >= 0; i--)
        cout << reverse_rows[i] << '\n';
}