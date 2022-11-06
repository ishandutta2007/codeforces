#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int minSum = 0;
        int maxSum = 0;
        int len = r - l + 1;
        for (int i = 1; i <= len; i++)
        {
            minSum += i;
            maxSum += n - i + 1;
        }
        if (s < minSum || s > maxSum)
        {
            cout << "-1\n";
            continue;
        }
        s -= minSum;
        for (int i = 0; i < len; i++)
        {
            ans[l + i - 1] = i + 1;
        }
        set<int> used;
        int mx = n;
        for (int i = r - 1; i >= l - 1; i--)
        {
            while (s && ans[i] < mx)
            {
                s--;
                ans[i]++;
            }
            mx = ans[i] - 1;
            used.insert(ans[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (i >= l - 1 && i <= r - 1)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (used.count(j))
                    continue;
                ans[i] = j;
                used.insert(j);
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
        }

    }
    return 0;
}