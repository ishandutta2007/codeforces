#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
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
            cin >> a[i];
        int ans = -1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[0])
            {
                if (i > 1)
                    ans = i;
                else if (a[0] == a[n - 1])
                    ans = i;
                else
                    ans = 0;
                break;
            }
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}