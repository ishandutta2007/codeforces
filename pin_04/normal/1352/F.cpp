#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (a && !b && !c)
        {
            for (int i = 0; i <= a; i++)
            {
                cout << 0;
            }
            cout << "\n";
            continue;
        } else if (!a && !b && c) {
            for (int i = 0; i <= c; i++)
            {
                cout << 1;
            }
            cout << "\n";
            continue;
        }
        for (int i = 0; i <= a; i++)
        {
            cout << 0;
        }
        for (int i = 0; i <= c; i++)
        {
            cout << 1;
        }
        b--;
        while (b >= 2)
        {
            cout << "01";
            b -= 2;
        }
        if (b) cout << 0;
        cout << "\n";
    }
    return 0;
}