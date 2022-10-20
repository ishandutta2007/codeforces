#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        if (a != b + 1) {
            cout << "NO\n";
            continue;
        }
        a += b;
        int f=  0;
        for (int i = 2; 1ll * i * i <= a; i++) {
            if (a % i == 0) {
                f = 1;
                break;
            }
        }
        cout << (f ? "NO" : "YES") << '\n';
    }
    return 0;
}