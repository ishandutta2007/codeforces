#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    const int LIM = (1 << 30) - 1;
    const int HALF = (1 << 15) - 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<vector<int>, int> solutions;
    vector<int> hash_set;

    for (int BITS = 0; BITS <= HALF; BITS++) { // 15 high
        hash_set.clear();
        for (int i = 0; i < N; i++) {
            hash_set.emplace_back(__builtin_popcount(BITS ^ (A[i] >> 15)));
        }
        int mn = *min_element(hash_set.begin(), hash_set.end());
        for (int i = 0; i < N; i++) {
            hash_set[i] = hash_set[i] - mn;
        }
        solutions[hash_set] = BITS;
    }

    for (int BITS = 0; BITS <= HALF; BITS++) { // 15 low
        hash_set.clear();
        for (int i = 0; i < N; i++) {
            hash_set.emplace_back(__builtin_popcount(BITS ^ (A[i] & HALF)));
        }

        int mx = *max_element(hash_set.begin(), hash_set.end());
        for (int i = 0; i < N; i++) {
            hash_set[i] = mx - hash_set[i];
        }

        if (solutions.count(hash_set) == 0) continue;
        cout << ((solutions[hash_set] << 15) | BITS) << "\n";
        return 0;

    }

    cout << -1 << "\n";
    return 0;

}