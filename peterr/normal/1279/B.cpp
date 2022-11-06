#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int parts[MAXN + 1];
long long pre[MAXN + 1];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
        {
            cin >> parts[i];
            pre[i] = pre[i - 1] + parts[i];
        }
        if (s >= pre[n])
            cout << 0 << endl;
        else
        {
            int gifts = 0;
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                int t = 0;
                for (int jump = n / 2 + 1; jump > 0; jump /= 2)
                {
                    while (t + jump <= n && pre[t + jump] - parts[i] <= s)
                        t += jump;
                }
                if (t >= i)
                {
                    if (t - 1 > gifts)
                    {
                        gifts = t - 1;
                        ans = i;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}