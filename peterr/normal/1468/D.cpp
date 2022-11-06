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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if (a > b)
        {
            a = n - a + 1;
            b = n - b + 1;
        }
        int num = b - a - 1;
        vector<int> s(m);
        for (int i = 0; i < m; i++)
        {
            cin >> s[i];
        }
        sort(s.rbegin(), s.rend());
        int ans = 0;
        int ptr = 0;
        int time = b - 2;
        while (num && ptr < m)
        {
            while (ptr < m && s[ptr] > time)
                ptr++;
            if (ptr < m)
            {
                ans++;
                time--;
                ptr++;
                num--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}