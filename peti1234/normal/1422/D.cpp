#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long m, n, x[c], y[c], dist[c];
vector<pair<int, int> > xr, yr;
vector<int> sz[c], s[c];
bool v[c];
priority_queue<pair<long long, int> > q;
int t(int a, int b) {
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
void add(int a, int b, int c) {
    sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), s[b].push_back(c);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> x[0] >> y[0];
    cin >> x[n+1] >> y[n+1];
    add(0, n+1, t(0, n+1));
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        xr.push_back({x[i], i});
        yr.push_back({y[i], i});
        sz[0].push_back(i);
        s[0].push_back(min(abs(x[i]-x[0]), abs(y[i]-y[0])));
        add(i, n+1, t(i, n+1));
    }
    sort(xr.begin(), xr.end()), sort(yr.begin(), yr.end());
    for (int i=1; i<n; i++) {
        int id=xr[i].second, el=xr[i-1].second, tav=x[id]-x[el];
        add(id, el, tav);
        id=yr[i].second, el=yr[i-1].second, tav=y[id]-y[el];
        add(id, el, tav);
    }
    q.push({0, 0});
    while(q.size()>0) {
        int tav=-q.top().first, id=q.top().second;
        q.pop();
        if (!v[id]) {
            v[id]=1, dist[id]=tav;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i], y=s[id][i];
                if (!v[x]) {
                    q.push({-tav-y, x});
                }
            }
        }
    }
    cout << dist[n+1] << "\n";
    return 0;
}