#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1E5;
pair<int, int> instant[MAXM];
int dist[MAXM];
bool visited[MAXM];
map<int, int> xset;
map<int, int> yset;
int par[MAXM];
int sz[MAXM];
vector<int> comps[MAXM];

int getRoot(int x)
{
    if (par[x] != x)
        par[x] = getRoot(par[x]);
    return par[x];
}

void mge(int x, int y)
{
    int r1 = getRoot(x);
    int r2 = getRoot(y);
    if (r1 == r2)
        return;
    if (sz[r1] > sz[r2])
        swap(r1, r2);
    par[r1] = r2;
    sz[r2] += sz[r1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < m; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> instant[i].first >> instant[i].second;
        if (xset.count(instant[i].first))
        {
            mge(i, xset[instant[i].first]);
        }
        if (yset.count(instant[i].second))
        {
            mge(i, yset[instant[i].second]);
        }
        xset[instant[i].first] = i;
        yset[instant[i].second] = i;
    }
    for (auto it = xset.begin(); it != xset.end(); it++)
    {
        xset[it->first] = getRoot(it->second);
    }
    for (auto it = yset.begin(); it != yset.end(); it++)
    {
        yset[it->first] = getRoot(it->second);
    }
    for (int i = 0; i < m; i++)
    {
        comps[getRoot(i)].push_back(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + m, 2E9 + 5);
    for (int i = 0; i < m; i++)
    {
        if (comps[i].empty())
            continue;
        int walk = 2E9 + 5;
        for (int ind : comps[i])
        {
            walk = min(walk, abs(fx - instant[ind].first) + abs(fy - instant[ind].second));
        }
        dist[i] = walk;
        pq.push(make_pair(walk, i));
    }
    while (!pq.empty())
    {
        pair<int, int> pr = pq.top();
        int cur = pr.second;
        int d = pr.first;
        pq.pop();
        if (visited[cur])
            continue;
        visited[cur] = true;
        for (int ind : comps[cur])
        {
            int x = instant[ind].first;
            int y = instant[ind].second;
            auto it = xset.upper_bound(x);
            if (it != xset.end())
            {
                int diff = abs(x - it->first);
                if ((long long) d + diff < dist[it->second])
                {
                    dist[it->second] = d + diff;
                    pq.push(make_pair(d + diff, it->second));
                }
            }
            it = yset.upper_bound(y);
            if (it != yset.end())
            {
                int diff = abs(y - it->first);
                if ((long long) d + diff < dist[it->second])
                {
                    dist[it->second] = d + diff;
                    pq.push(make_pair(d + diff, it->second));
                }
            }
            it = xset.lower_bound(x);
            if (it!= xset.begin())
            {
                it--;
                int diff = abs(x - it->first);
                if ((long long) d + diff < dist[it->second])
                {
                    dist[it->second] = d + diff;
                    pq.push(make_pair(d + diff, it->second));
                }
            }
            it = yset.lower_bound(y);
            if (it != yset.begin())
            {
                it--;
                int diff = abs(y - it->first);
                if ((long long) d + diff < dist[it->second])
                {
                    dist[it->second] = d + diff;
                    pq.push(make_pair(d + diff, it->second));
                }
            }
        }
    }
    long long ans = abs(sx - fx) + abs(sy - fy);
    for (int i = 0; i < m; i++)
    {
        if (comps[i].empty())
            continue;
        //cout << "diff " << i << " " << dist[i] << endl;
        long long temp = 2E9 + 5;
        for (int ind : comps[i])
        {
            temp = min(temp, (long long) abs(sx - instant[ind].first));
            temp = min(temp, (long long) abs(sy - instant[ind].second));
        }
        temp += dist[i];
        ans = min(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}