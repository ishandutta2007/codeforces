#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<int>> go(N + 1, vector<int>(20, N));
    vector<int> last(20, N);
    for (int i = N - 1; i >= 0; i--) {
        for (int k = 0; k < 20; k++) {
            if (A[i] & (1 << k)) {
                go[i][k] = min(go[i][k], last[k]);
                for (int j = 0; j < 20; j++) {
                    go[i][j] = min(go[i][j], go[last[k]][j]);
                }
            }
        }
        for (int j = 0; j < 20; j++) {
            if (A[i] & (1 << j)) {
                last[j] = i;
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bool can = false;
        for (int j = 0; j < 20; j++) {
            if ((A[y] & (1 << j)) && go[x][j] <= y) {
                can = true;
                break;
            }
        }
        if (can) {
            cout << "Shi\n";
        } else {
            cout << "Fou\n";
        }
    }
    return 0;
}