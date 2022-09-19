#include<bits/stdc++.h>

using namespace std;
const int c=20202;
int n, m, szint[c], pos[c], f;
vector<pair<int, pair<int, int> > > el;
vector<int> sz[c], ki[c], s[c];
queue<int> q;
void add(int a, int b) {
    ki[a].push_back(sz[b].size()), ki[b].push_back(sz[a].size());
    sz[a].push_back(b), sz[b].push_back(a);
    s[a].push_back(1), s[b].push_back(0);
}
bool bfs() {
    for (int i=0; i<=f; i++) {
        szint[i]=0;
    }
    szint[0]=1;
    q.push(0);
    while(q.size()>0) {
        int a=q.front();
        q.pop();
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i], y=s[a][i];
            if (y && !szint[x]) {
                szint[x]=szint[a]+1;
                q.push(x);
            }
        }
    }
    return szint[f];
}
int dfs(int a, int b, int d) {
    if (a==b) {
        return d;
    }
    for (; pos[a]<sz[a].size(); pos[a]++) {
        int x=sz[a][pos[a]], y=s[a][pos[a]];
        if (szint[a]+1==szint[x] && y) {
            int z=dfs(x, b, y);
            if (z) {
                s[a][pos[a]]-=z;
                s[x][ki[a][pos[a]]]+=z;
                return z;
            }
        }
    }
    return 0;
}
int solve(int mid) {
    for (int i=0; i<=f; i++) {
        sz[i].clear(), ki[i].clear(), s[i].clear();
    }
    for (int i=0; i<=mid; i++) {
        int a=el[i].second.first, b=el[i].second.second;
        add(a, b);
    }
    int ans=0;
    while(bfs()) {
        for (int i=0; i<=f; i++) {
            pos[i]=0;
        }
        while(int x=dfs(0, f, 1)) {
            ans+=x;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m, f=2*n+1;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        el.push_back({c, {a, n+b}});
    }
    for (int i=1; i<=n; i++) {
        el.push_back({0, {0, i}});
        el.push_back({0, {i+n, f}});
    }
    sort(el.begin(), el.end());
    m=el.size();
    int lo=-1, hi=m;
    while (hi-lo>1) {
        int mid=(hi+lo)/2;
        if (solve(mid)==n) hi=mid;
        else lo=mid;
    }
    if (hi==m) cout << -1 << "\n";
    else cout << el[hi].first << "\n";
    return 0;
}
/*
3 4
1 2 4
1 3 1
2 1 2
3 1 3
*/