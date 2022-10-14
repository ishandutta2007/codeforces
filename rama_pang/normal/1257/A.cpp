#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) {
        lint n, x, a, b; cin >> n >> x >> a >> b;
        if (a > b) swap(a, b);
        while (a > 1 && x > 0) {
            a--;
            x--;
            if (x == 0) break;
        }
        while (b < n && x > 0) {
            b++;
            x--;
            if (x == 0) break;
        }
        cout << abs(b - a) << '\n';
    }
}