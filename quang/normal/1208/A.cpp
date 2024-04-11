#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b;
        c = a ^ b;
        int n;
        cin >> n;
        n %= 3;
        if (n == 0) cout << a << endl;
        else if (n == 1) cout << b << endl;
        else cout << c << endl;
    }
    return 0;
}