#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inverse_perm(const vector<int> &perm) {
    int n = perm.size();
    vector<int> inv(n, -1);

    for (int i = 0; i < n; i++)
        inv[perm[i]] = i;

    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> R(N);
    vector<int> C(N);

    for (int &r : R) {
        cin >> r;
        r--;
    }

    for (int &c : C) {
        cin >> c;
        c--;
    }

    vector<int> inv_R = inverse_perm(R);
    vector<int> inv_C = inverse_perm(C);
    vector<pair<int, int>> portals;

    for (int current = 0; current < N; current++) {
        int row = inv_R[current];
        int col = inv_C[current];

        if (row != current || col != current) {
            portals.emplace_back(row, current);
            portals.emplace_back(current, col);
        }

        swap(inv_R[current], inv_R[R[current]]);
        swap(inv_C[current], inv_C[C[current]]);
        swap(R[current], R[row]);
        swap(C[current], C[col]);
        assert(inv_R[current] == current && inv_C[current] == current);
        assert(R[current] == current && C[current] == current);
    }

    cout << portals.size() / 2 << '\n';

    for (int i = 0; i < (int) portals.size(); i++)
        cout << portals[i].first + 1 << ' ' << portals[i].second + 1 << (i % 2 == 0 ? ' ' : '\n');
}