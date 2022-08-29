#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q, X;
    cin >> Q >> X;
    vector<int> counts(X, 0);
    int answer = 0;

    for (int q = 0; q < Q; q++) {
        int y;
        cin >> y;
        counts[y % X]++;

        while (counts[answer % X] > answer / X)
            answer++;

        cout << answer << '\n';
    }
}