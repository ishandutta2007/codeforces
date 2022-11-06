#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        long long sticks = (long long) k * y + k;
        long long ans = k + (sticks - 3 + x) / (x - 1);
        cout << ans << "\n";
    }
    return 0;
}