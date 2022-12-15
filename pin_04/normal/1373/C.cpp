#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax = 1e6 + 5;

int a[Nmax];

signed main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        s = ' ' + s;
        for (int i = 1; i <= n; i++)
        {
            a[i] = a[i - 1];
            if (s[i] == '+') a[i]++;
            else a[i]--;
        }
        for (int i = 2; i <= n; i++)
        {
            a[i] = min(a[i], a[i - 1]);
        }
        int ans = 0;
        for (int sum = 0; sum <= n; sum++)
        {
            int l = 0;
            int r = n + 1;
            while (r - l > 1)
            {
                int mid = (l + r) >> 1;
                if (sum + a[mid] < 0) r = mid;
                else l = mid;
            }
            if (r > n)
            {
                ans += n;
                break;
            } else {
                ans += r;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}