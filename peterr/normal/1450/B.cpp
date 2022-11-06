#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
pair<int, int> a[MAXN];

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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) > k)
                    break;
                if (j == n - 1)
                    ans = 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}