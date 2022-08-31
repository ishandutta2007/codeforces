#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int M_MAX = 1e5 + 5;

int N;
vector<int> prices[M_MAX];

long long win_cost(int votes) {
    long long cost = 0;
    int needed = votes - (int) prices[0].size();
    vector<int> remaining;

    for (int p = 1; p < M_MAX; p++) {
        int start_index = max((int) prices[p].size() - (votes - 1), 0);

        for (int i = 0; i < start_index; i++) {
            cost += prices[p][i];
            needed--;
        }

        for (int i = start_index; i < (int) prices[p].size(); i++)
            remaining.push_back(prices[p][i]);
    }

    if (needed > 0) {
        nth_element(remaining.begin(), remaining.begin() + needed, remaining.end());

        for (int i = 0; i < needed; i++)
            cost += remaining[i];
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int p, c;
        cin >> p >> c;
        prices[p].push_back(c);
    }

    for (int p = 0; p < M_MAX; p++)
        sort(prices[p].begin(), prices[p].end());

    int low = 1, high = N;

    while (low < high) {
        int mid = (low + high) / 2;

        if (win_cost(mid) < win_cost(mid + 1))
            high = mid;
        else
            low = mid + 1;
    }

    cout << win_cost(low) << '\n';
    return 0;
}