#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cur = 0;
        for (int i = 1; i <= 60; i++)
        {
            int h = (1LL << i) - 1;
            if (cur + h * (h + 1) / 2 <= n)
            {
                cur += h * (h + 1) / 2;
            } else {
                cout << i - 1 << "\n";
                break;
            }
        }
    }
    return 0;
}