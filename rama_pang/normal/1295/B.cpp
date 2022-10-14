#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, X;
        string S;
        cin >> N >> X >> S;
        vector<int> bal(N + 1);
        for (int i = 1; i <= N; i++) {
            bal[i] = bal[i - 1];
            if (S[i - 1] == '0') {
                bal[i]++;
            } else {
                bal[i]--;
            }
        }
        int thisIteration = 0;
        for (int i = 0; i <= N; i++) {
            if (bal[i] == X) {
                thisIteration++;
            }
        }
        if (bal[N] == 0 && thisIteration) {
            cout << -1 << "\n";
            continue;
        }
        if (bal[N] == 0 && thisIteration == 0) {
            cout << 0 << "\n";
            continue;
        }
        int nxtIteration = bal[N];
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            int cur = X - bal[i];
            if (cur < 0 && nxtIteration > 0) continue;
            if (cur > 0 && nxtIteration < 0) continue;
            if ((X - bal[i]) % nxtIteration == 0) {
                ans++;
            }
        }
        if (X == 0) {
            ans++;
        }
        cout << ans << "\n";

    }

}