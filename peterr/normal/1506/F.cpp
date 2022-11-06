#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> a[MAXN + 1];

int getId(int r, int c)
{
    return r - c;
}

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
        a[0] = {1, 1};
        n++;
        for (int i = 1; i < n; i++)
        {
            cin >> a[i].first;
        }
        for (int i = 1; i < n; i++)
        {
            cin >> a[i].second;
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (i == 1 && a[i].first == 1 && a[i].second == 1)
                continue;
            int id1 = getId(a[i - 1].first, a[i - 1].second);
            int id2 = getId(a[i].first, a[i].second);
            if (id1 == id2)
            {
                if (!(id1 & 1))
                {
                    ans += a[i].first - a[i - 1].first;
                }
            }
            else
            {
                id1 /= 2;
                id2 /= 2;
                ans += abs(id1 - id2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}