#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    lint ans = 0, l = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int k = 1; i - 2 * k >= l; k++) {
            if (s[i] == s[i - k] && s[i - k] == s[i - 2 * k]) {
                l = i - 2 * k + 1;
            }
        }
        ans += l;
    }

    cout << ans << "\n";
    return 0;
}