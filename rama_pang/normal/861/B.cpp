#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> K(M), F(M);
    for (int i = 0; i < M; i++) {
        cin >> K[i] >> F[i];
    }

    int ans = 0;
    int num = 0;
    bool many = false;
    for (int flat = 1; flat <= 1000; flat++) {
        bool can = true;
        for (int i = 0; i < M; i++) {
            if (ceil(1.00 * K[i] / flat) != F[i]) {
                can = false;
                break;
            }
        }
        if (can) {
            num++;
            if (ans == 0) {
                ans = ceil(1.00 * N / flat);
                many = true;
            } else if (ans != ceil(1.00 * N / flat)) {
                many = false;
                break;
            }
        }
    }

    if (many) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;

}