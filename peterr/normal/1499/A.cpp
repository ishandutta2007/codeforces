#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        cout << (2 * w <= k1 + k2 && 2 * b <= 2 * n - k1 - k2 ? "YES" : "NO") << "\n";
    }
    return 0;
}