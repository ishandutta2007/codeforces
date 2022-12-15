#include <bits/stdc++.h>

using namespace std;
const int Nmax = 2e5 + 5;

int n;
int a[Nmax];

bool flag[Nmax];

int main()
{
    //freopen("file.ip","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            flag[i] = false;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] %= n;
            if (a[i] < 0) a[i] += n;
            flag[(i + a[i]) % n] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (!flag[i]) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}