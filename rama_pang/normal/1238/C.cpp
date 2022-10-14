#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int H, N;
        cin >> H >> N;
        vector<int> A(N + 1);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int last = 0, ans = 0;
        for (int i = 0; i <= N; i++) {
            if (i > 0 && A[i] + 1 < A[i - 1]) {
                if (last > 0) {
                    ans += (i - last) % 2;
                } else {
                    ans += 1 - ((i - last) % 2);
                }
                last = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}