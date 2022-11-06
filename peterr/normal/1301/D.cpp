#include <bits/stdc++.h>

using namespace std;

pair<int, string> ans[3000];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (4 * n * m - 2 * n - 2 * m >= k)
    {
        int temp = 0;
        int ind = 0;
        if (k && m > 1)
        {
            temp = min(k, m - 1);
            ans[ind++] = make_pair(temp, "R");
            k -= temp;
        }
        if (k && m > 1)
        {
            temp = min(k, m - 1);
            ans[ind++] = make_pair(temp, "L");
            k -= temp;
        }
        int r = 1;
        while (k && r < n)
        {
            ans[ind++] = make_pair(1, "D");
            k--;
            if (k && m > 1)
            {
                temp = min(m - 1, k / 3);
                if (temp < m - 1 && k % 3 != 0)
                {
                    if (temp)
                        ans[ind++] = make_pair(temp, "RUD");
                    if (k % 3 == 1)
                        ans[ind++] = make_pair(1, "R");
                    else if (k % 3 == 2)
                        ans[ind++] = make_pair(1, "RU");
                    k = 0;
                }
                else
                {
                    ans[ind++] = make_pair(temp, "RUD");
                    k -= temp * 3;
                }
            }
            if (k && m > 1)
            {
                temp = min(m - 1, k);
                ans[ind++] = make_pair(temp, "L");
                k -= temp;
            }
            r++;
        }
        if (k)
        {
            temp = min(n - 1, k);
            ans[ind++] = make_pair(temp, "U");
            k -= temp;
        }
        cout << "YES" << endl;
        cout << ind << endl;
        for (int i = 0; i < ind; i++)
            cout << ans[i].first << " " << ans[i].second << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}