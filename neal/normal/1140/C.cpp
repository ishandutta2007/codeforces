#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> songs(N);

    for (int i = 0; i < N; i++)
        cin >> songs[i].second >> songs[i].first;

    sort(songs.rbegin(), songs.rend());
    priority_queue<int, vector<int>, greater<int>> lengths;
    long long length_sum = 0, best = 0;

    for (int i = 0; i < N; i++) {
        length_sum += songs[i].second;
        lengths.push(songs[i].second);

        while ((int) lengths.size() > K) {
            length_sum -= lengths.top();
            lengths.pop();
        }

        best = max(best, songs[i].first * length_sum);
    }

    cout << best << '\n';
}