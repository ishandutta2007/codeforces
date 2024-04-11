#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int len = 1; len <= 9; len++) {
            int step = 0;
            for (int j = 0; j < len; j++) {
                step *= 10;
                step++;
            }
            int cur = step;
            for (int j = 1; j <= 9; j++) {
                if (cur <= n) {
                    ans++;
                } else {
                    break;
                }
                cur += step;
            }
        }

        cout << ans << "\n";
    }

}