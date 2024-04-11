#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> P;

void solve_case() {
    cin >> N;
    P.resize(N);

    for (int &p : P)
        cin >> p;

    int gold = 1;

    while (gold < N && P[gold - 1] == P[gold])
        gold++;

    vector<int> changes;

    for (int i = 1; i < N; i++)
        if (P[i] != P[i - 1])
            changes.push_back(i);

    int G = 0, S = 0, B = 0;

    for (int bronze = 1; bronze < N; bronze++) {
        if (2 * bronze > N)
            continue;

        if (P[bronze - 1] == P[bronze])
            continue;

        int minimum = 2 * gold + 1;
        auto it = lower_bound(changes.begin(), changes.end(), minimum);

        if (it != changes.end() && *it < bronze - gold) {
            G = gold;
            S = *it - gold;
            B = bronze - *it;
        }
    }

    cout << G << ' ' << S << ' ' << B << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}