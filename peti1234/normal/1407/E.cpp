#include <bits/stdc++.h>

using namespace std;
const int c=500002;
vector<int> sz[c], s[c];
int n, m, bl[c], w[c], dist[c];
bool v[c], cl[c];
priority_queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[b].push_back(a), s[b].push_back(c);
    }
    q.push({0, n});
    while(q.size()>0) {
        int t=q.top().first, id=q.top().second;
        q.pop(), t*=-1;
        if (!v[id]) {
            v[id]=true, dist[id]=t;
            if (w[id]>bl[id]) cl[id]=1;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i], y=s[id][i];
                if (!v[x]) {
                    if (y) if (w[x]==0 || t+1<w[x]) w[x]=t+1;
                    if (!y) if (bl[x]==0 || t+1<bl[x]) bl[x]=t+1;
                    if (w[x] && bl[x]) q.push({-max(w[x], bl[x]), x});
                }
            }
        }
    }
    for (int i=1; i<=n; i++) if (!v[i]) {
        if (w[i]==0) cl[i]=1;
    }
    if (!v[1]) cout << -1 << "\n";
    else cout << dist[1] << "\n";
    for (int i=1; i<=n; i++) cout << cl[i];
    cout << "\n";
    return 0;
}