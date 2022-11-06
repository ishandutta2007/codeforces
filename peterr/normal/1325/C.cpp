#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int ans[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(i);
        adjList[b].push_back(i);
    }
    int leaves = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((int) adjList[i].size() == 1)
        {
            leaves++;
        }
    }
    if (leaves == 2)
    {
        for (int i = 0; i < n - 1; i++)
            cout << i << "\n";
    }
    else
    {
        fill(ans, ans + n, -1);
        int cnt = 0;
        for (int i = 1; i <= n && cnt <= 2; i++)
        {
            if ((int) adjList[i].size() == 1)
            {
                ans[adjList[i][0]] = cnt++;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (ans[i] == -1)
            {
                ans[i] = cnt++;
            }
        }
        for (int i = 0; i < n - 1; i++)
            cout << ans[i] << "\n";
    }
    return 0;
}