#include <bits/stdc++.h>
 
using namespace std;
const int c=100005;
int n, m, k, w, szint[c], ki[c][21];
long long sok=1000000000000000;
bool v[c];
long long dist[c], maxi[c][21];
vector<int> sz[c], f[c];
vector<long long> s[c];
priority_queue<pair<long long, int> > q;
priority_queue<pair<long long, pair<int, int> > > z;
void dfs(int a)
{
    for (int i=1; i<=20; i++) {
        ki[a][i]=ki[ki[a][i-1]][i-1];
        maxi[a][i]=max(maxi[ki[a][i-1]][i-1], maxi[a][i-1]);
    }
    for (int i=0; i<f[a].size(); i++) {
        int x=f[a][i];
        szint[x]=szint[a]+1;
        dfs(x);
    }
}
long long solve(int a, int b)
{
    long long ans=0;
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=20; i>=0; i--) {
        int x=ki[a][i];
        if (szint[x]>=szint[b]) {
            ans=max(ans, maxi[a][i]);
            a=x;
        }
    }
    for (int i=20; i>=0; i--) {
        int x=ki[a][i], y=ki[b][i];
        if (x!=y) {
            ans=max({ans, maxi[a][i], maxi[b][i]});
            a=x, b=y;
        }
    }
    if (a!=b) {
        ans=max({ans, maxi[a][0], maxi[b][0]});
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> w;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b);
        sz[b].push_back(a);
        s[a].push_back(c);
        s[b].push_back(c);
    }
    for (int i=k+1; i<=n; i++) {
        dist[i]=sok;
    }
    for (int i=1; i<=k; i++) {
        q.push({0, i});
    }
    while(q.size()>0) {
        long long a=q.top().first;
        int id=q.top().second;
        q.pop();
        if (!v[id]) {
            dist[id]=-a;
            v[id]=true;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i];
                long long y=s[id][i];
                if (!v[x]) {
                    q.push({a-y, x});
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        v[i]=false;
        for (int j=0; j<sz[i].size(); j++) {
            int a=sz[i][j];
            s[i][j]+=dist[a]+dist[i];
        }
    }
    z.push({0, {1, 0}});
    while(z.size()>0) {
        long long a=z.top().first;
        int id=z.top().second.first;
        int hol=z.top().second.second;
        z.pop();
        if (!v[id]) {
            v[id]=true;
            ki[id][0]=hol;
            maxi[id][0]=-a;
            f[hol].push_back(id);
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i];
                long long y=s[id][i];
                if (!v[x]) {
                    z.push({-y, {x, id}});
                }
            }
        }
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=w; i++) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}