#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int a[MAXN];

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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int cur = min(a[i], a[i + 1]) * 2;
            while (cur < max(a[i + 1], a[i]))
            {
                ans++;
                cur *= 2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}