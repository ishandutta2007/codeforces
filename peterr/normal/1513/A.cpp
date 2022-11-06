#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cur = n;
        if (k > (n - 1) / 2)
        {
            cout << "-1\n";
            continue;
        }
        fill(ans, ans + n, -1);
        for (int i = 0; i < k; i++)
        {
            ans[2 * i + 1] = cur--;
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == -1)
                ans[i] = cur--;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}