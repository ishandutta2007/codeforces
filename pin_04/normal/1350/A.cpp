#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[1000005];

void init()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (f[i]) continue;
        f[i] = i;
        for (int j = i * i; j <= 1000000; j += i)
        {
            if (f[j]) continue;
            f[j] = i;
        }
    }
}

signed main()
{
    //freopen("file.inp","r",stdin);
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        if (n % 2)
        {
            k--;
            n += f[n];
        }
        n += 2 * k;
        cout << n << "\n";
    }
    return 0;
}