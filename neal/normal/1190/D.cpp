#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 1e9 + 5;

int N;
vector<pair<int, int>> points;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    points.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {y, x};
    }

    sort(points.rbegin(), points.rend());
    ordered_set<int> x_coords;
    long long total = 0;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && points[i].first == points[j].first) {
            x_coords.insert(points[j].second);
            j++;
        }

        long long size = x_coords.size();
        total += size * (size + 1) / 2;

        vector<int> indices = {-1, (int) size};

        for (int k = i; k < j; k++)
            indices.push_back(x_coords.order_of_key(points[k].second));

        sort(indices.begin(), indices.end());
        indices.resize(unique(indices.begin(), indices.end()) - indices.begin());

        for (int k = 0; k + 1 < (int) indices.size(); k++) {
            long long gap = indices[k + 1] - indices[k] - 1;
            total -= gap * (gap + 1) / 2;
        }
    }

    cout << total << '\n';
}