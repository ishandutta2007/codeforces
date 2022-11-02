#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int l = 0, r = 1e9;
        while(r - l > 1)
        {
            int mid = (r + l) / 2;
            int sum = mid + (mid / 7) * 2;
            if (sum <= a + b + c)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        int col = l / 7;
        if (l + col * 2 != a + b + c || l % 7 != 0)
        {
            cout << "NO\n";
        }
        else
        {
            if (min({a, b, c}) < col)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
    return 0;
}