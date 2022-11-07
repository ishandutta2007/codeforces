#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int drinks[MAXN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        drinks[x]++;
    }
    int ans = 0;
    for (int j = 0; j < (n + 1) / 2; j++)
    {
        bool found = false;
        for (int i = 1; i <= k; i++)
        {
            if (drinks[i] >= 2)
            {
                ans += 2;
                drinks[i] -= 2;
                found = true;
                break;
            }
        }
        if (!found)
        {
            for (int i = 1; i <= k; i++)
            {
                if (drinks[i] > 0)
                {
                    ans++;
                    drinks[i]--;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}