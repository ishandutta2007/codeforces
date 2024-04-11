#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, R;
        cin >> N >> R;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int S = 0;
        sort(begin(A), end(A));
        A.resize(unique(begin(A), end(A)) - begin(A));
        for (int i = (int)A.size() - 1; i >= 0; i--) {
            if (A[i] - S * R > 0) {
                S++;
            }
        }
        cout << S << "\n";
    }


}