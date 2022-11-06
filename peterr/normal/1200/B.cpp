#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int height[MAXN];

bool solve(int n, int m, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (height[i] < height[i + 1] - k)
        {
            int diff = height[i + 1] - k - height[i];
            if (m >= diff)
            {
                m -= diff;
            }
            else
            {
                return false;
            }
        }
        else
        {
            m += min(height[i], height[i] - (height[i + 1] - k));
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        if (solve(n, m, k))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}