#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> P, C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    P.resize(N);
    C.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];

        if (P[i] > 0)
            P[i]--;
    }

    vector<bool> good_child(N, false);

    for (int i = 0; i < N; i++)
        if (C[i] == 0 && P[i] >= 0)
            good_child[P[i]] = true;

    bool first = true;

    for (int i = 0; i < N; i++)
        if (C[i] == 1 && !good_child[i]) {
            if (!first)
                cout << ' ';

            first = false;
            cout << i + 1;
        }

    if (first)
        cout << -1;

    cout << '\n';
}