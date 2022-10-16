#include <bits/stdc++.h>

using namespace std;

int N, K;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    int ans = 0;
    int prv = -1;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        if (t == prv) {
            ans = max(ans, cur);
            cur = 1;
            prv = t;
        } else {
            cur++;
            prv = t;
        }
    }
    ans = max(ans, cur);
    cout << ans << endl;
}