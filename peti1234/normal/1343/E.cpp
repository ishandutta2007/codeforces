#include <bits/stdc++.h>

using namespace std;
const long long sok=500000000000000001, c=200001;
int w, n, m, x, y, z, tav[c][3];
vector<int> sz[c];
long long kom[c], mini;
bool v[c];
queue<pair<int, int> > q;
void bfs(int a, int p) {
    for (int i=1; i<=n; i++) v[i]=0, tav[i][p]=0;
    q.push({a, 0});
    while(q.size()>0) {
        int id=q.front().first, dist=q.front().second;
        q.pop();
        if (!v[id]) {
            v[id]=true, tav[id][p]=dist;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i];
                if (!v[x]) q.push({x, dist+1});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m >> x >> y >> z, mini=sok;
        for (int i=1; i<=n; i++) sz[i].clear();
        for (int i=1; i<=m; i++) cin >> kom[i];
        sort(kom+1, kom+m+1);
        for (int i=1; i<=m; i++) kom[i]+=kom[i-1];
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        bfs(x, 0), bfs(y, 2), bfs(z, 1);
        for (int i=1; i<=n; i++) {
            int a=tav[i][0]+tav[i][1], b=tav[i][2];
            if (a+b<=m) mini=min(mini, kom[b]+kom[a+b]);
        }
        cout << mini << "\n";
    }
    return 0;
}
/*
1
4 3 2 3 4
1 2 3
1 2
1 3
1 4
*/