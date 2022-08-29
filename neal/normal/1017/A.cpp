#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> scores;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        scores.emplace_back(-(a + b + c + d), i);
    }

    sort(scores.begin(), scores.end());

    for (int i = 0; i < N; i++)
        if (scores[i].second == 0)
            cout << i + 1 << '\n';

    return 0;
}