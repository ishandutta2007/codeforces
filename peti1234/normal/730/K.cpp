#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int w, n, m, fel[c], le[c], szint[c], st[c], kezd, veg;
vector<int> sz[c], visz[c];
bool v[c];
vector<pair<int, int> > ans;
queue<pair<int, int> > q;
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a, le[a]=x;
            dfs(x);
        } else if (x!=fel[a] && szint[x]<szint[a]) {
            visz[le[x]].push_back(a);
        }
    }
}
void pb(int a, int b, int dir) {
    if (dir%2==0) {
        swap(a, b);
    }
    ans.push_back({a, b});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> kezd >> veg;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        szint[kezd]=1;
        dfs(kezd);
        q.push({veg, 1});
        while (q.size()>0) {
            int id=q.front().first, dir=q.front().second;
            q.pop();
            for ( ; fel[id] && !st[id]; id=fel[id]) {
                st[id]=dir;
                int ff=fel[id];
                pb(ff, id, dir);
                for (auto kov:visz[id]) {
                    pb(ff, kov, dir);
                    q.push({kov, dir+1});
                }
            }
        }

        if (ans.size()!=m) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (auto x:ans) {
                cout << x.first << " " << x.second << "\n";
            }
        }

        for (int i=1; i<=n; i++) {
            fel[i]=0, le[i]=0, szint[i]=0, st[i]=0, v[i]=0;
            sz[i].clear(), visz[i].clear();
        }
        ans.clear();
    }
    return 0;
}