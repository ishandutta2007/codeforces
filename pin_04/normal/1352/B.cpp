#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        if (k > n || (n % 2 && k % 2 == 0) || (n % 2 == 0 && k % 2 && k * 2 > n))
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (n % 2)
        {
            for (int i = 1; i < k; i++)
            {
                cout << 1 << " ";
                n--;
            }
            cout << n << " ";
            cout << "\n";
        } else {
            if (k % 2)
            {
                for (int i = 1; i < k; i++)
                {
                    cout << 2 << " ";
                    n -= 2;
                }
                cout << n << " ";
                cout << "\n";
            } else {
                for (int i = 1; i < k; i++)
                {
                    cout << 1 << " ";
                    n--;
                }
                cout << n << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}