#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int even = 0;
        bool close = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (!(a[i] & 1))
                even++;
            for (int j = 0; j < i; j++)
            {
                if (abs(a[i] - a[j]) == 1)
                    close = true;
            }
        }
        if (even % 2 == 0 || close)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}