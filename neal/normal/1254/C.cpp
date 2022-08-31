#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;

long long query(int t, int i, int j, int k) {
    assert(1 <= t && t <= 2);
    cout << t << ' ' << i << ' ' << j << ' ' << k << endl;
    long long result;
    cin >> result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    int first = 1, second = 2;

    for (int i = 3; i <= N; i++)
        if (query(2, first, second, i) < 0)
            second = i;

    vector<long long> area(N + 1, 0);

    for (int i = 2; i <= N; i++)
        if (i != second)
            area[i] = query(1, first, second, i);

    long long largest_area = -1;
    int largest = -1;

    for (int i = 2; i <= N; i++)
        if (i != second && area[i] > largest_area) {
            largest_area = area[i];
            largest = i;
        }

    assert(largest > 0);
    vector<int> side(N + 1, 0);

    for (int i = 2; i <= N; i++)
        if (i != second && i != largest)
            side[i] = query(2, first, largest, i);

    vector<int> ordering = {first, second};
    vector<pair<long long, int>> area_sorted;

    for (int i = 2; i <= N; i++)
        if (area[i] > 0)
            area_sorted.emplace_back(area[i], i);

    sort(area_sorted.begin(), area_sorted.end());

    for (pair<long long, int> &as : area_sorted) {
        int index = as.second;

        if (side[index] < 0)
            ordering.push_back(index);
    }

    ordering.push_back(largest);
    reverse(area_sorted.begin(), area_sorted.end());

    for (pair<long long, int> &as : area_sorted) {
        int index = as.second;

        if (side[index] > 0)
            ordering.push_back(index);
    }

    assert((int) ordering.size() == N);
    cout << 0;

    for (int x : ordering)
        cout << ' ' << x;

    cout << endl;
}