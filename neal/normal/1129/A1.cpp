#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

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

    for (int source = 0; source < N; source++) {
        int worst = 0;

        for (int i = 0; i < N; i++)
            if (candy_count[i] > 0)
                worst = max(worst, (i + N - source) % N + (candy_count[i] - 1) * N + closest_candy[i]);

        cout << worst << (source < N - 1 ? ' ' : '\n');
    }
}