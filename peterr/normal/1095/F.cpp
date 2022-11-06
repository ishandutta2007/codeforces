#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 2E5;
pair<long long, int> vertices[MAXN + 1];
bool visited[MAXN + 1];
vector<pair<int, ll>> offers[MAXN + 1];
int convert[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> vertices[i].first;
        vertices[i].second = i;
    }
    sort(vertices + 1, vertices + n + 1);
    for (int i = 1; i <= n; i++)
    {
        convert[vertices[i].second] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x = convert[x];
        y = convert[y];
        offers[x].push_back({y, w});
        offers[y].push_back({x, w});
    }
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    for (pair<int, ll> p : offers[1])
    {
        pq.push({p.second, p.first, 1});
    }
    int cur = 2;
    long long ans = 0;
    visited[1] = true;
    while (cur <= n)
    {
        int nextV;
        ll baseCost = vertices[cur].first + vertices[1].first;
        while (!pq.empty() && get<0>(pq.top()) < baseCost && visited[get<1>(pq.top())] && visited[get<2>(pq.top())])
            pq.pop();
        if (!pq.empty() && get<0>(pq.top()) < baseCost)
        {
            ans += get<0>(pq.top());
            if (visited[get<1>(pq.top())])
                nextV = get<2>(pq.top());
            else
                nextV = get<1>(pq.top());
        }
        else
        {
            ans += baseCost;
            nextV = cur;
        }
        for (pair<int, ll> p : offers[nextV])
        {
            if (!visited[p.first])
            {
                pq.push({p.second, p.first, nextV});
            }
        }
        visited[nextV] = true;
        while (visited[cur])
            cur++;
    }
    cout << ans << endl;

    return 0;
}