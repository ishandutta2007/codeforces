#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int b[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int mn = 1000000000;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            mn = min(mn, a[i]);
        }
        sort(b, b + n);
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % mn != 0)
            {
                if (a[i] != b[i])
                    ans = false;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}