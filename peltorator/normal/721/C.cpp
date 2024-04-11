#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

vector< pair<int, int> > g[5001];
vector< vector<int> > d, p;
vector<int> ans;

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    d.resize(n + 1, vector<int> (n, 2e9));
    p.resize(n + 1, vector<int> (n));
    for (int i = 0; i < m; i++)
    {
        int k, l, w;
        cin >> k >> l >> w;
        g[k].push_back({l, w});
    }
    d[1][0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[j][i - 1] != 2e9)
            {
                for (int k = 0; k < g[j].size(); k++)
                {
                    int u = g[j][k].first;
                    long long w = g[j][k].second;
                    if (d[u][i] > d[j][i - 1] + w)
                    {
                        d[u][i] = d[j][i - 1] + w;
                        p[u][i] = j;
                    }
                }
            }
        }
    }
    int answ;
    for (int i = 1; i < n; i++)
        if (d[n][i] <= t)
            answ = i;
    answ;
    ans.push_back(n);
    int v = n;
    while(v != 1)
    {
        v = p[v][answ];
        answ--;
        ans.push_back(v);
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}