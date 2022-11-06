#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = n / k * k;
        n %= k;
        ans += min(k / 2, n % k);
        cout << ans << endl;
    }
    return 0;
}