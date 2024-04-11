#include <bits/stdc++.h>

using namespace std;
const int c=100002, d=22;
int n, m, w, szint[c], szom[c][d], t[d];
vector<int> sz[c], s[c];
vector<int> el;
bool v[c];
long long dist[c][d], fel[c][d];
priority_queue<pair<long long, int> > q;
void dfs(int a) {
    v[a]=true;
    int f=szom[a][0];
    for (int i=1; i<d; i++) {
        szom[a][i]=szom[f][i-1], fel[a][i]=fel[a][i-1]+fel[f][i-1];
        f=szom[f][i-1];
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x]) {
            szint[x]=szint[a]+1, szom[x][0]=a, fel[x][0]=y;
            dfs(x);
        } else if (szint[a]<szint[x]) el.push_back(a);
    }
}
void dij(int a, int e) {
    for (int i=1; i<=n; i++) v[i]=0;
    q.push({0, a});
    while(q.size()>0) {
        long long dis=q.top().first, id=q.top().second;
        q.pop();
        if (!v[id]) {
            dist[id][e]=-dis;
            v[id]=1;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i], y=s[id][i];
                if (!v[x]) q.push({dis-y, x});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), s[b].push_back(c);
    }
    szint[1]=1, dfs(1);
    for (int i=0; i<el.size(); i++) dij(el[i], i);
    cin >> w;
    for (int i=1; i<=w; i++) {
        int a, b;
        long long mini=1e15, sum=0;
        cin >> a >> b;
        for (int i=0; i<el.size(); i++) mini=min(mini, dist[a][i]+dist[b][i]);
        if (szint[a]<szint[b]) swap(a, b);
        for (int i=d-1; i>=0; i--) {
            int x=szom[a][i];
            if (szint[x]>=szint[b]) sum+=fel[a][i], a=x;
        }
        for (int i=d-1; i>=0; i--) {
            int x=szom[a][i], y=szom[b][i];
            if (x!=y) sum+=fel[a][i]+fel[b][i], a=x, b=y;
        }
        if (a!=b) sum+=fel[a][0]+fel[b][0];
        cout << min(mini, sum) << "\n";
    }
    return 0;
}