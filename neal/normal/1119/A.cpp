#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> colors;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    colors.resize(N);

    for (int i = 0; i < N; i++)
        cin >> colors[i];

    int best = 0;

    for (int i = 0; i < N; i++) {
        if (colors[i] != colors[0])
            best = max(best, i);

        if (colors[i] != colors[N - 1])
            best = max(best, N - 1 - i);
    }

    cout << best << '\n';
}