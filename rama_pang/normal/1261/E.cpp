#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int N; cin >> N;
    vector<int> A(N);
    vector<vector<bool>> ans(N + 1, vector<bool>(N, 0));

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cur = 0;
    for (int j = N; j >= 0; j--) {
        for (int i = 0; i < N; i++) {
            if (A[i] == j) {
                for (int k = 0; k < A[i]; k++) {
                    ans[(cur + k) % (N + 1)][i] = 1;
                }
                cur++;
            }
        }
    }

    cout << N + 1 << "\n";
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

}