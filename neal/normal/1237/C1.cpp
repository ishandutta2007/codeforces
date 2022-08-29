#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> points;

int solve(int dimension, int start, int end) {
    if (end - start == 1)
        return start;

    assert(dimension < 3);
    vector<int> unpaired;

    for (int i = start, j = start; i < end; i = j) {
        while (j < end && points[i][dimension] == points[j][dimension])
            j++;

        int remain = solve(dimension + 1, i, j);

        if (remain >= 0)
            unpaired.push_back(remain);
    }

    for (int i = 0; i + 1 < (int) unpaired.size(); i += 2)
        cout << points[unpaired[i]][3] << ' ' << points[unpaired[i + 1]][3] << '\n';

    return unpaired.size() % 2 == 0 ? -1 : unpaired.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    points.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        points[i] = {x, y, z, i + 1};
    }

    sort(points.begin(), points.end());
    solve(0, 0, N);
}