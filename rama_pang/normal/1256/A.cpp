#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    int Q; cin  >> Q;
    while (Q--) {
        lint a, b, n, s;
        cin >> a >> b >> n >> s;
        if (a * n + b < s) {
            cout << "NO\n";
        } else {
            lint m = s / n;
            lint t = n * min(m, a);

            if (s - t > b) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}