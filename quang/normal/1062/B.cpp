#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > divs;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            divs.emplace_back(i, 0);
            while (n % i == 0) {
                n /= i;
                divs.back().second++;
            }
        }
    }
    int res = 1;
    int mx = 0;
    for (auto u : divs) {
        res *= u.first;
        mx = max(mx, u.second);
    }
    int ans = (mx != (mx & -mx));
    for (auto u : divs) {
        if (u.second != mx) ans |= 1;
    }
    int cur = 1;
    while (cur < mx) {
        cur *= 2;
        ans++;
    }
    cout << res << " " << ans << endl;
    return 0;
}