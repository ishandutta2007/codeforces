#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    //freopen("file.inp","r",stdin);
    int q;
    cin >> q;
    while (q--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (a < c) cout << "1 ";
        else cout << "-1 ";
        if (a * b <= c) cout << "-1 ";
        else cout << b;
        cout << "\n";
    }
    return 0;
}