#include <bits/stdc++.h>
using namespace std;
using lint = long long;

map<pair<int, pair<int, int>>, int> memo;
int solve(int a, int b, int c) {
    if (min({a, b, c}) < 0) return -1e9;
    if (memo.count({a, {b, c}})) {
        return memo[{a, {b, c}}];
    }
    int res = 0;
    res = max(res, 1 + solve(a, b - 1, c - 1));
    res = max(res, 1 + solve(a - 1, b - 1, c));
    res = max(res, 1 + solve(a - 1, b, c - 1));
    return memo[{a, {b, c}}] = res;

}

int main() {

    int t; cin >> t;
    while (t--) {
        lint a[3]; cin >> a[0] >> a[1] >> a[2];
        lint ans = 0;
        
        while (true) {
            sort(a, a + 3);
            if (a[0] == a[1] && a[2] - a[1] <= 1) {
                lint tmp = a[0];
                tmp /= 2;
                ans += tmp * 3;
                a[0] -= 2 * tmp;
                a[1] -= 2 * tmp;
                a[2] -= 2 * tmp;
                ans += solve(a[0], a[1], a[2]);
                break;
            } else if (a[1] >= 1 && a[2] >= 1) {
                ans += a[1] - a[0];
                lint k = a[1] - a[0];
                a[1] -= k;
                a[2] -= k;
                if (k == 0) {
                    k = a[2] - a[1];
                    if (a[0] < k) k = a[0];
                    a[2] -= 2 * k;
                    a[1] -= k;
                    a[0] -= k;
                    ans += 2 * k;
                }
            } else {
                break;
            }
        }
        
        cout << ans << "\n";
        
    }

}