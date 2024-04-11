#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> cards;

bool possible(int steps) {
    vector<bool> seen(N + 1, false);

    if (steps < N) {
        int need = N - steps;

        for (int i = 2 * N - need, j = 1; i < 2 * N; i++, j++)
            if (cards[i] != j)
                return false;

        for (int i = 0; i < N; i++)
            seen[cards[i]] = true;

        for (int i = need; i < N; i++) {
            if (!seen[i + 1])
                return false;

            seen[cards[N + i - need]] = true;
        }

        return true;
    }

    if (steps >= N) {
        for (int i = 0; i < steps; i++)
            seen[cards[i]] = true;

        for (int i = 0; i < N; i++) {
            if (!seen[i + 1])
                return false;

            if (steps + i < 2 * N)
                seen[cards[steps + i]] = true;
        }

        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cards.resize(2 * N);

    for (int &card : cards)
        cin >> card;

    int potential = N - cards.back();

    if (possible(potential)) {
        cout << potential << '\n';
        return 0;
    }

    int low = N, high = 2 * N;

    while (low < high) {
        int mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
}