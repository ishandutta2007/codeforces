#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, M;
vector<int> candy_count, closest_candy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    candy_count.assign(N, 0);
    closest_candy.assign(N, N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        candy_count[a]++;
        closest_candy[a] = min(closest_candy[a], (b + N - a) % N);
    }

    vector<int> cost(N, -INF);

    for (int i = 0; i < N; i++)
        if (candy_count[i] > 0)
            cost[i] = i + (candy_count[i] - 1) * N + closest_candy[i];

    vector<int> prefix_max(N + 1, -INF);
    vector<int> suffix_max(N + 1, -INF);

    for (int i = 0; i < N; i++)
        prefix_max[i + 1] = max(prefix_max[i], cost[i]);

    for (int i = N - 1; i >= 0; i--)
        suffix_max[i] = max(suffix_max[i + 1], cost[i]);

    for (int source = 0; source < N; source++) {
        int answer = max(suffix_max[source], prefix_max[source] + N) - source;
        cout << answer << (source < N - 1 ? ' ' : '\n');
    }
}