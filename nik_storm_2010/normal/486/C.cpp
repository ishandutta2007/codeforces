#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    p--;
    if (p > (n - 1) / 2) p = n - p - 1;
    int ll = +2e9, rr = -2e9, ans = 0;
    for (int l = 0, r = n - 1; l <= r; l++, r--) {
        if (s[l] == s[r]) continue;
        int c1 = s[l] - 'a';
        int c2 = s[r] - 'a';
        if (c1 > c2) swap(c1, c2);
        ans += min(abs(c2 - c1), abs(c2 - c1 - 26));
        ll = min(ll, l);
        rr = max(rr, l);
    }
    if (ll == +2e9) cout << "0\n"; else
    if (rr <= p) cout << ans + p - ll << "\n"; else
    if (p <= ll) cout << ans + rr - p << "\n"; else
    if (rr - p <= p - ll) cout << ans + rr - p + rr - ll << "\n"; else cout << ans + p - ll + rr - ll << "\n";
    return 0;
}