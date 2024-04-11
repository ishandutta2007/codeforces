#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans += (k - a[i]) / a[0];
        }
        cout << ans << "\n";
    }
    return 0;
}