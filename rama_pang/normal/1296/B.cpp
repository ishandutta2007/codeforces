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

        while (n > 0) {
            int spend = n / 10;
            if (spend == 0) {
                ans += n;
                break;
            }
            n -= 10 * spend;
            ans += 10 * spend;
            n += spend;
        }

        cout << ans << "\n";
    }

}