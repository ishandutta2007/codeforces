#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> prices;

long long win_cost(int votes) {
    long long cost = 0;
    int needed = votes - (int) prices[0].size();
    vector<int> remaining;

    for (int p = 1; p < M; p++) {
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

    cin >> N >> M;
    prices.resize(M);

    for (int i = 0; i < N; i++) {
        int p, c;
        cin >> p >> c;
        p--;
        prices[p].push_back(c);
    }

    for (int p = 0; p < M; p++)
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