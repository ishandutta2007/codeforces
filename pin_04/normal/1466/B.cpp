#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector <int> a(n + 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        a[n] = (int) 1e9;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] + 1 < a[i + 1])
                a[i]++;
        }

        int ans = 1;
        for (int i = 1; i < n; i++)
            ans += (a[i] != a[i - 1]);
        cout << ans << "\n";
    }

    return 0;
}