#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
int pre[201][MAXN + 1];

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
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 1; j <= 200; j++)
            {
                pre[j][i] = pre[j][i - 1];
                if (j == a[i])
                    pre[j][i]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= 200; i++)
        {
            int p1, p2;
            p1 = 1;
            p2 = n;
            int cnt = 1;
            while (p1 <= p2)
            {
                while (p1 <= p2 && a[p1] != i)
                    p1++;
                while (p2 >= p1 && a[p2] != i)
                    p2--;
                if (p1 > p2)
                    break;
                if (p1 == p2 - 1)
                {
                    ans = max(ans, 2 * cnt);
                }
                else if (p1 == p2)
                {
                    ans = max(ans, 2 * cnt - 1);
                }
                else
                {
                    for (int j = 1; j <= 200; j++)
                    {
                        ans = max(ans, 2 * cnt + pre[j][p2 - 1] - pre[j][p1]);
                    }
                }
                cnt++;
                p1++;
                p2--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}