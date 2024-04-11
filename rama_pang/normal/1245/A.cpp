#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        if (__gcd(a, b) != 1) {
            cout << "Infinite\n";
        } else {
            cout << "Finite\n";
        }
    }

}