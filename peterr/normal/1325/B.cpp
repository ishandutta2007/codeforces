#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
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
        sort(a, a + n);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}