#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint a[3];
lint ans = 1e18;

void brute(int n) {
    if (n == 3) {
        ans = min(ans, abs(a[2] - a[1]) + abs(a[2] - a[0]) + abs(a[1] - a[0]));
        return;
    }
    a[n]++;
    brute(n + 1);
    a[n]--;
    a[n]--;
    brute(n + 1);
    a[n]++;
    brute(n + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2];
        ans = 1e18;
        brute(0);
        cout << ans << "\n";
    }
}