#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int A_MAX = 2e5 + 5;
const int INF = 1e9 + 5;

int N, K;
vector<int> A;
vector<vector<int>> costs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    costs.assign(A_MAX, {});

    for (int a : A) {
        costs[a].push_back(0);
        int count = 0;

        do {
            a /= 2;
            count++;
            costs[a].push_back(count);
        } while (a != 0);
    }

    int best = INF;

    for (int a = 0; a < A_MAX; a++)
        if ((int) costs[a].size() >= K) {
            nth_element(costs[a].begin(), costs[a].begin() + K, costs[a].end());
            int sum = 0;

            for (int k = 0; k < K; k++)
                sum += costs[a][k];

            best = min(best, sum);
        }

    cout << best << '\n';
}