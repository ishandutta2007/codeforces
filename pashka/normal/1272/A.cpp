#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int a, b, c;
    cin >> a >> b >> c;
    long res = (long)1e10;
    for (int aa = a - 1; aa <= a + 1; aa++) {
        for (int bb = b - 1; bb <= b + 1; bb++) {
            for (int cc = c - 1; cc <= c + 1; cc++) {
                long s = (long)abs(aa - bb) +
                        (long)abs(bb - cc) +
                        (long)abs(aa - cc);
                res = min(res, s);
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}