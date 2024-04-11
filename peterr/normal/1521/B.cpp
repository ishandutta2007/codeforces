#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];

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
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ind = distance(a, min_element(a + 1, a + n + 1));
        int num = a[ind];
        int other = num + 1;
        while (__gcd(num, other) != 1)
            other++;
        vector<tuple<int, int, int, int>> ans;
        for (int i = 1; i <= n; i++)
        {
            if (i == ind)
                continue;
            if (abs(i - ind) & 1)
            {
                ans.push_back({ind, i, num, other});
            }
            else
            {
                ans.push_back({ind, i, num, num});
            }
        }
        cout << ans.size() << "\n";
        for (tuple<int, int, int, int> tup : ans)
        {
            cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << " " << get<3>(tup) << "\n";
        }
    }
    return 0;
}