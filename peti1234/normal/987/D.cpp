#include <bits/stdc++.h>

using namespace std;
int n, m, k, s;
int t[100001];
vector<int> sz[100001];
int mini[100001][101];
void bfs(int x)
{
    queue<pair<int, int > > q;
    while(q.size()>0) {
        q.pop();
    }
    bool v[100001];
    for (int i=1; i<=n; i++) {
        if (t[i]==x) {
            q.push({i, 0});
        }
        v[i]=false;
    }
    while(q.size()>0) {
        int a=q.front().first;
        int b=q.front().second;
        if (!v[a]) {
            v[a]=true;
            mini[a][x]=b;
            for (int i=0; i<sz[a].size(); i++) {
                int y=sz[a][i];
                if (!v[y]) {
                    q.push({y, b+1});
                }
            }
        }
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> s;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    for (int i=1; i<=k; i++) {
        bfs(i);
    }
    for (int i=1; i<=n; i++) {
        sort(mini[i]+1, mini[i]+k+1);
    }
    for (int i=1; i<=n; i++) {
        int v=0;
        for (int j=1; j<=s; j++) {
            v+=mini[i][j];
        }
        cout << v << " ";
    }
    return 0;
}