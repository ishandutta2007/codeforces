#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int S, B;
    cin >> S >> B;

    vector<int> A(S);
    for (int i = 0; i < S; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> Base(B);
    for (int i = 0; i < B; i++) {
        cin >> Base[i].first >> Base[i].second;
    }
    sort(begin(Base), end(Base));

    for (int i = 1; i < B; i++) {
        Base[i].second += Base[i - 1].second;
    }

    for (int i = 0; i < S; i++) {
        int id = upper_bound(begin(Base), end(Base), make_pair(A[i], (int)1e9 + 100)) - begin(Base);
        cout << ((id > 0) ? Base[id - 1].second : 0) << " \n"[i == S - 1];
    }
    return 0;
}