#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;
const int N = 1e5 + 5;

int a[N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "1 1\n" << -a[1] << "\n";
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
    } else {
        cout << "1 " << n - 1 << "\n";
        for (int i = 1; i <= n - 1; i++)
        {
            int d = a[i] % n;
            a[i] += d * (n - 1);
            cout << d * (n - 1) << " ";
        }
        cout << "\n";
        cout << n << " " << n << " " << -a[n] << "\n";
        a[n] = 0;
        cout << "1 " << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << -a[i] << " ";
        }
    }
    return 0;
}