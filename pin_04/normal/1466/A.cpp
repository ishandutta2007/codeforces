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
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        vector <int> s(0);
        for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            s.push_back(a[j] - a[i]);
        }
        sort(s.begin(), s.end());
        int ans = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}