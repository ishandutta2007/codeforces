#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int ans = INT_MAX, ans1 = -1, ans2 = -1, ans3 = -1;

        for (int i = 1; i <= 20000; i++) {
            for (int j = i; j <= 20000; j += i) {
                int temp = abs(a - i) + abs(b - j);
                if (c > c % j and c % j < j - c % j) {
                    if (temp + c % j < ans) {
                        ans = temp + c % j;
                        ans1 = i;
                        ans2 = j;
                        ans3 = c - c % j;
                    }
                } else {
                    if (temp + j - c % j < ans) {
                        ans = temp + j - c % j;
                        ans1 = i;
                        ans2 = j;
                        ans3 = c + j - c % j;
                    }
                }
            }
        }

        cout << ans << "\n";
        cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }
    return 0;
}