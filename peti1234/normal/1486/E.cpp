#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=52;
int n, m, dist[c][k];
bool v[c][k];
vector<pair<int, int> > sz[c];
priority_queue<pair<int, pair<int, int> > > q;
void add(int a, int b, int c) {
    q.push({-a, {b, c}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back({b, c});
        sz[b].push_back({a, c});

    }
    add(0, 1, 0);
    while (q.size()>0) {
        int ert=-q.top().first;
        int id=q.top().second.first, be=q.top().second.second;
        q.pop();
        if (!v[id][be]) {
            v[id][be]=1;
            dist[id][be]=ert;
            for (auto i:sz[id]) {
                int x=i.first, y=i.second;
                int uj=0, pl=y*y+2*be*y;
                if (!be) uj=y;
                if (!v[x][uj]) {
                    add(ert+pl, x, uj);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << (v[i][0] ? dist[i][0]: -1) << " ";
    }
    return 0;
}