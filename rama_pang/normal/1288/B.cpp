#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    /*
        a + b + ab = conc(a, b)
        (a + 1)(b + 1) - 1 = conc(a, b)
        (a + 1)(b + 1) = 1 + conc(a, b)
        d = digits of b
        1 + conc(a, b) = 1 + a * 10^d + b
        (a + 1)(b + 1) = a*10^d + (b + 1)
        a(b + 1) = a * (10^d)
        (b + 1) = 10^d
        b = 9, 99, 999, ...
    */

    auto solve = [&](lint a, lint b) {
        lint d = log10(b) + 1;
        lint cur = 0, cnt = 0;
        while (cur <= b) {
            cur = cur * 10 + 9;
            if (cur <= b) {
                cnt++;
            } else {
                break;
            }
        }
        return a * cnt;
    };
    
    int T;
    cin >> T;
    while (T--) {
        lint A, B;
        cin >> A >> B;
        lint ans = 0;
        ans += solve(A, B);
        cout << ans << "\n";

    }


}