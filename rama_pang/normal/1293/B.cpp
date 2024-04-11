#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1.00 / i;
    }
    cout << fixed << setprecision(10) << ans << "\n";

}