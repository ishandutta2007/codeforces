#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
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
        int last = a[n - 1] + 3;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] + 1 < last)
            {
                last = a[i] + 1;
                ans++;
            }
            else if (a[i] + 1 == last)
            {
                last = a[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}