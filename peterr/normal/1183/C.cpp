#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int k, n, a, b;
        cin >> k >> n >> a >> b;
        if ((ll) b * n >= k)
            cout << -1 << endl;
        else
        {
            int ans = 0;
            for (int jump = 1e9 / 2; jump > 0; jump /= 2)
            {
                while (ans + jump <= n && (ll) (ans + jump) * a + (ll) (n - (ans + jump)) * b < k)
                    ans += jump;
            }
            cout << ans << endl;
        }
    }
    return 0;
}