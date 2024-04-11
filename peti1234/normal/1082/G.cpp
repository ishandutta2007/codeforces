#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, m, kezd, veg, pos[c], szint[c];
long long sum, ans, sok=1e12;
vector<int> sz[c], ki[c];
vector<long long> s[c];
void add(int a, int b, long long c) {
    ki[a].push_back(sz[b].size()), ki[b].push_back(sz[a].size());
    sz[a].push_back(b), sz[b].push_back(a);
    s[a].push_back(c), s[b].push_back(0);
}
long long dfs(int a, long long ert) {
    //cout << "dfs " << a << " " << ert << endl;
    if (a==veg) {
        return ert;
    }
    for (; pos[a]<sz[a].size(); pos[a]++) {
        int x=sz[a][pos[a]];
        long long suly=s[a][pos[a]];
        if (szint[x]==szint[a]+1 && suly) {
            long long add=dfs(x, min(ert, suly));
            if (add) {
                s[a][pos[a]]-=add;
                s[x][ki[a][pos[a]]]+=add;
                return add;
            }
        }
    }
    return 0;
}
bool bfs() {
    for (int i=kezd; i<=veg; i++) {
        szint[i]=0;
    }
    szint[kezd]=1;
    queue<int> q;
    q.push(kezd);
    while(q.size()>0) {
        int a=q.front();
        q.pop();
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i];
            long long suly=s[a][i];
            if (suly && !szint[x]) {
                szint[x]=szint[a]+1;
                q.push(x);
            }
        }
    }
    return szint[veg];
}
long long dinic() {
    long long ans=0;
    while(bfs()) {
        for (int i=kezd; i<=veg; i++) {
            pos[i]=0;
        }
        while(long long add=dfs(kezd, sok)) {
            ans+=add;
        }
    }
    return ans;
}
int main()
{
    cin >> n >> m, veg=n+m+1;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        add(i, veg, x);
    }
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sum+=c;
        add(kezd, n+i, c);
        add(n+i, a, sok), add(n+i, b, sok);
    }
    cout << sum-dinic() << "\n";
    return 0;
}