#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
pair<int, int> l[MAXN];
int ans[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> l[i].first;
        l[i].second = i;
        sum += l[i].first;
    }
    if (sum < n)
    {
        cout << -1 << endl;
    }
    else
    {
        int furthest = n - l[m - 1].first + 1 - (m - 1);
        if (furthest <= 0)
            cout << -1 << endl;
        else
        {
            ans[m - 1] = n - l[m - 1].first + 1;
            int extra = furthest - 1;
            int cur = n - l[m - 1].first + 1;
            bool valid = true;
            for (int i = m - 2; i >= 0; i--)
            {
                int target = max(cur - 1 - extra, cur - l[i].first);
                ans[i] = target;
                extra -= (cur - 1) - (target);
                cur = target;
                if (target + l[i].first - 1 > n)
                    valid = false;
            }
            if (cur != 1)
                valid = false;
            if (!valid)
                cout << -1 << endl;
            else
            {
                for (int i = 0; i < m; i++)
                    cout << ans[i] << " \n"[i == m - 1];
            }

        }
    }
    return 0;
}