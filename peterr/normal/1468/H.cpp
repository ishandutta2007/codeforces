#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        vector<int> v(m);
        vector<bool> keep(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            keep[x] = true;
        }
        int rem = k / 2;
        if ((n - m) % (2 * rem) != 0)
        {
            cout << "NO\n";
            continue;
        }
        int half = (n - m) / 2;
        int l = 0;
        int cnt = 0;
        while (cnt < half)
        {
            l++;
            while (keep[l])
                l++;
            cnt++;
        }
        int r = l + 1;
        if (keep[r])
        {
            cout << "YES\n";
            continue;
        }
        int mn = n + 1;
        int num = 0;
        while (l >= 1 && !keep[l])
        {
            l--;
            num++;
        }
        mn = min(mn, num);
        num = 0;
        while (r <= n && !keep[r])
        {
            r++;
            num++;
        }
        mn = min(mn, num);
        if (half - mn >= rem)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}