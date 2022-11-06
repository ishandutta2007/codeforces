#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
vector<int> adjList1[MAXN + 1];
vector<int> adjList2[MAXN + 1];
pair<int, int> intervals[MAXN + 1];
set<int> inRange;
int other[2 * MAXN];
bool active[2 * MAXN];
int curTime;
int ans;
int cnt;

void dfs1(int v, int p)
{
    intervals[v].first = curTime++;
    for (int adj : adjList2[v])
    {
        if (adj == p)
            continue;
        dfs1(adj, v);
    }
    intervals[v].second = curTime++;
    other[intervals[v].first] = intervals[v].second;
    other[intervals[v].second] = intervals[v].first;
}

void dfs2(int v, int p)
{
    int startTime = intervals[v].first;
    int endTime = intervals[v].second;
    auto it = inRange.upper_bound(startTime);
    if (it == inRange.end() || *it > endTime)
    {
        active[startTime] = true;
        it = inRange.lower_bound(startTime);
        if (it == inRange.begin())
        {
            cnt++;
        }
        else
        {
            it--;
            if (!active[*it] || other[*it] < startTime)
            {
                cnt++;
            }
            else
            {
                active[*it] = false;
            }
        }
    }
    inRange.insert(startTime);
    ans = max(ans, cnt);
    for (int adj : adjList1[v])
    {
        if (adj == p)
            continue;
        dfs2(adj, v);
    }
    inRange.erase(startTime);
    if (active[startTime])
    {
        active[startTime] = false;
        cnt--;
        it = inRange.lower_bound(startTime);
        if (it != inRange.begin())
        {
            it--;
            if (!active[*it] && other[*it] > startTime)
            {
                int otherStart = *it;
                it++;
                if (it == inRange.end() || *it > other[otherStart])
                {
                    cnt++;
                    active[otherStart] = true;
                }
            }
        }
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
        for (int i = 1; i <= n; i++)
        {
            adjList1[i].clear();
            adjList2[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int p;
            cin >> p;
            adjList1[i + 2].push_back(p);
            adjList1[p].push_back(i + 2);
        }
        for (int i = 0; i < n - 1; i++)
        {
            int p;
            cin >> p;
            adjList2[i + 2].push_back(p);
            adjList2[p].push_back(i + 2);
        }
        curTime = 0;
        dfs1(1, 1);
        ans = 0;
        cnt = 0;
        fill(active, active + 2 * n, false);
        dfs2(1, 1);
        cout << ans << "\n";
    }
    return 0;
}