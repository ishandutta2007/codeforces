#include <bits/stdc++.h>

using namespace std;
const int c=1002;
long long dist[c][c], sum, maxi, h, o=0;
int n, m, k, x[c], y[c], f[c], g[c];
vector<int> sz[c], s[c];
bool v[c];
priority_queue<pair<long long, int> > q;
void d(int a) {
    for (int i=1; i<=n; i++) v[i]=0;
    q.push({0, a});
    while(q.size()>0) {
        long long tav=-q.top().first, id=q.top().second;
        q.pop();
        if (!v[id]) {
            v[id]=1, dist[a][id]=tav;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i], y=s[id][i];
                if (!v[x]) {
                    q.push({-tav-y, x});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        f[i]=a, g[i]=b;
        sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), s[b].push_back(c);
    }
    for (int i=1; i<=n; i++) {
        d(i);
    }
    for (int i=1; i<=k; i++) {
        cin >> x[i] >> y[i];
        sum+=dist[x[i]][y[i]];
    }
    for (int i=1; i<=m; i++) {
        h=0;
        for (int j=1; j<=k; j++) {
            h+=max(o, dist[x[j]][y[j]]-min(dist[x[j]][f[i]], dist[x[j]][g[i]])-min(dist[y[j]][f[i]], dist[y[j]][g[i]]));
        }
        maxi=max(maxi, h);
    }
    cout << sum-maxi << "\n";
    return 0;
}
/*
3 2 3
1 2 2
2 3 3
1 2
1 3
2 3
*/