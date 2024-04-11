#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, k, dist[c], tav1[c], tav2[c], maxi;
vector<int> sz[c];
bool v[c], sp[c];
queue<pair<int, int> > q;
vector<pair<int, int> > p;
void bfs(int a) {
    for (int i=1; i<=n; i++) v[i]=0, tav2[i]=0;
    q.push({a, 0});
    while(q.size()>0) {
        int id=q.front().first, ert=q.front().second;
        q.pop();
        if (!v[id]) {
            v[id]=1;
            tav2[id]=ert;
            for (int x:sz[id]) {
                if (!v[x]) {
                    q.push({x, ert+1});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) {
        int x; cin >> x;
        sp[x]=1;
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    bfs(1);
    for (int i=1; i<=n; i++) tav1[i]=tav2[i];
    bfs(n);
    for (int i=1; i<=n; i++) {
        if (sp[i]) {
            p.push_back({tav1[i], tav2[i]});
        }
    }
    sort(p.begin(), p.end());
    for (int i=1; i<p.size(); i++) {
        maxi=max(maxi, p[i-1].first+1+p[i].second);
    }
    maxi=min(maxi, tav1[n]);
    cout << maxi << "\n";
    return 0;
}