#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, m, k, dist[c], db;
vector<pair<int, pair<int, int> > > sz[c];
bool v[c];
priority_queue<pair<long long, pair<int, int> > > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back({b, {c, 1}}), sz[b].push_back({a, {c, 1}});
    }
    for (int i=1; i<=k; i++) {
        int a, b;
        cin >> a >> b;
        sz[1].push_back({a, {b, 0}});
    }
    q.push({0, {1, 1}});
    while (q.size()>0) {
        long long id=q.top().second.first, tav=-q.top().first, t=q.top().second.second;
        q.pop();
        if (v[id]) continue;
        v[id]=true;
        if (!t) db++;
        dist[id]=tav;
        for (auto p:sz[id]) {
            int x=p.first;
            long long tav2=tav+p.second.first, t2=p.second.second;
            if (!v[x]) {
                q.push({-tav2, {x, t2}});
            }
        }
    }
    cout << k-db << "\n";
    return 0;
}