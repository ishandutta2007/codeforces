#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto check = [&](int n) {
        int last = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] + n < M) {
                if (A[i] + n < last) {
                    return false;
                }
                last = max(last, A[i]);
            } else {
                int k = A[i] + n - M;
                if (k >= last) {
                    continue;
                } else {
                    if (A[i] + n < last) {
                        return false;
                    }
                    last = max(last, A[i]);
                }
            }
        }
        return true;
    };

    int le = 0, ri = M;
    while (le < ri) {
        int mid = (le + ri) / 2;
        if (check(mid)) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }

    cout << ri << "\n";
    return 0;
}