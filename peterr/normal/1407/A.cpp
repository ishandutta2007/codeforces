#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int k = n;
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] + a[i + 1] == 1)
            {
                k--;
                if (a[i] == 1)
                    a[i] = -1;
                else
                    a[i + 1] = -1;
            }
        }
        cout << k << "\n";
        for (int i = 0; i < n; i++)
        {
            if (a[i] != -1)
                cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}