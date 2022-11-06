#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        map<pair<int, int>, int> used;
        int x, y;
        x = y = 0;
        int ans = 1E6;
        int l, r;
        l = r = 0;
        used[make_pair(0, 0)] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'U')
                y++;
            else if (s[i - 1] == 'D')
                y--;
            else if (s[i - 1] == 'R')
                x++;
            else
                x--;
            pair<int, int> key = make_pair(x, y);
            if (used.count(key))
            {
                int ind = used[key];
                int diff = i - ind;
                if (diff < ans)
                {
                    ans = diff;
                    l = ind + 1;
                    r = i;
                }
            }
            used[key] = i;
        }
        if (ans == 1E6)
            cout << -1 << endl;
        else
            cout << l << " " << r << endl;
    }
    return 0;
}