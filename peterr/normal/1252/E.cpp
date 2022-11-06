#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> voters[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> voters[i].first >> voters[i].second;
        }
        sort(voters, voters + n);
        long long ans = 0;
        int bought = 0;
        priority_queue<int, vector<int>, greater<int>> costs;
        for (int i = n - 1; i >= 0; i--)
        {
            costs.push(voters[i].second);
            if (voters[i].first - bought > i)
            {
                ans += costs.top();
                costs.pop();
                bought++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}