#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Q; cin  >> Q;
    while (Q--) {
        lint a, b, n, s;
        cin >> n;
        int A[n];
        int can[n] = {};
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) {
            int mn = 105, id = -1;
            for (int j = 0; j < n - 1; j++) {
                if (can[j]) continue;
                if (mn > A[j + 1] && A[j] > A[j + 1]) {
                    mn = A[j + 1];
                    id = j;
                }
            }
            if (id == -1) continue;
            can[id] = 1;
            swap(A[id], A[id + 1]);
        }

        for (int i = 0; i < n; i++) cout << A[i] << " ";
        cout << "\n";
    }
}