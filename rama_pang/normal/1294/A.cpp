#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int sum = a + b + c + n;
        if (sum % 3 != 0) {
            cout << "NO\n";
            continue;
        }
        sum /= 3;
        if (sum >= max({a, b, c})) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}