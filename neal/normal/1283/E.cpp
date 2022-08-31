#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N);
    vector<bool> house(N + 2, false);

    for (int &x : X) {
        cin >> x;
        house[x] = true;
    }

    sort(X.begin(), X.end());
    int minimum = 0;
    int current = 1;

    while (current <= N)
        if (house[current]) {
            minimum++;
            current += 3;
        } else {
            current++;
        }

    int maximum = 0;
    int empty = 0;

    for (int x : X) {
        empty = max(empty, x - 1);

        if (empty <= x + 1) {
            maximum++;
            empty++;
        }
    }

    cout << minimum << ' ' << maximum << '\n';
}