#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
    long long x, y, n;
    cin >> x >> y >> n;

    long long ans;

    if (n % 6 == 1)
        ans = x;
    else if (n % 6 == 2)
        ans = y;
    else if (n % 6 == 3)
        ans = y - x;
    else if (n % 6 == 4)
        ans = -x;
    else if (n % 6 == 5)
        ans = -y;
    else
        ans = x - y;

    ans = ans % mod;

    if (ans < 0)
        cout << ans + mod;
    else
        cout << ans;

    return 0;
}