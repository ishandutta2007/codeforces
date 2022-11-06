#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int c[MAXN];

void solve(vector<int> &cost, int n, vector<long long> &res)
{
    int mn = cost[0];
    long long sum = 0;
    for (int i = 0; i < (int) cost.size(); i++)
    {
        sum += cost[i];
        mn = min(mn, cost[i]);
        res.push_back(sum + (long long) mn * max(0, n - i - 1));
    }
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
        vector<int> v1, v2;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            if (i & 1)
                v2.push_back(c[i]);
            else
                v1.push_back(c[i]);
        }
        vector<long long> a1, a2;
        solve(v1, n, a1);
        solve(v2, n, a2);
        long long ans = a1[0] + a2[0];
        for (int i = 0; i < (int) a1.size(); i++)
        {
            for (int j = max(i - 1, 0); j < min((int) a2.size(), i + 1); j++)
            {
                ans = min(ans, a1[i] + a2[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}