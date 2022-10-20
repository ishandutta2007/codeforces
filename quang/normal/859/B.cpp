#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = sqrt(n);
    int res = m * 4;
    n -= m * m;
    if (n == 0) {
    } else if (n <= m) {
        res += 2;
    } else if (n > m) {
        res += 4;
    }
    cout << res << endl;
    return 0;
}