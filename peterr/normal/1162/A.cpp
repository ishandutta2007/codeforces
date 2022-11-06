#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int height[MAXN + 1];

int main()
{
    int n, h, m;
    cin >> n >> h >> m;
    fill(height, height + MAXN + 1, h);
    for (int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        for (int j = l; j <= r; j++)
        {
            height[j] = min(height[j], x);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += height[i] * height[i];
    }
    cout << ans;
    return 0;
}