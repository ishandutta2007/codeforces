#include <bits/stdc++.h>

using namespace std;
const int Nmax = 1e5 + 5;

int n;
int a[Nmax];
int f[Nmax];

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            f[i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i * 2; j <= n; j += i)
            {
                if (a[j] > a[i])
                {
                    f[j] = max(f[j], f[i] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, f[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}