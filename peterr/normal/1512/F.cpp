#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        long long ans = 2E9;
        long long days = 0;
        long long money = 0;
        for (int i = 0; i < n; i++)
        {
            if (money >= c)
            {
                ans = min(ans, days);
            }
            else
            {
                int diff = c - (int) money;
                ans = min(ans, days + (diff + a[i] - 1) / a[i]);
            }
            if (i < n - 1)
            {
                if (money >= b[i])
                {
                    days++;
                    money -= b[i];
                }
                else
                {
                    int diff = b[i] - (int) money;
                    int num = (diff + a[i] - 1) / a[i];
                    money = money + (long long) num * a[i] - b[i];
                    days += num + 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}