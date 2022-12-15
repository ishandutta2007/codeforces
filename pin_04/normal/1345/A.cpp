#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        bool ok;
        if (n == 1 || m == 1) ok = true;
        else if (n <= 2 && m <= 2) ok = true;
        else ok = false;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}