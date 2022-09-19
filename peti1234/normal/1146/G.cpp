#include <bits/stdc++.h>

using namespace std;
int n, h, m, sum, f=1, sok=1e6;

const int c=20002;
int kezd, veg, pos[c], szint[c];
vector<int> sz[c], ki[c];
vector<int> s[c];
void add(int a, int b, int c) {
    ki[a].push_back(sz[b].size()), ki[b].push_back(sz[a].size());
    sz[a].push_back(b), sz[b].push_back(a);
    s[a].push_back(c), s[b].push_back(0);
}
int dfs(int a, int ert) {
    if (a==veg) {
        return ert;
    }
    for (; pos[a]<sz[a].size(); pos[a]++) {
        int x=sz[a][pos[a]];
        int suly=s[a][pos[a]];
        if (szint[x]==szint[a]+1 && suly) {
            int add=dfs(x, min(ert, suly));
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
            int suly=s[a][i];
            if (suly && !szint[x]) {
                szint[x]=szint[a]+1;
                q.push(x);
            }
        }
    }
    return szint[veg];
}
int dinic() {
    int ans=0;
    while(bfs()) {
        for (int i=kezd; i<=veg; i++) {
            pos[i]=0;
        }
        while(int add=dfs(kezd, sok)) {
            ans+=add;
        }
    }
    return ans;
}


int main()
{
    cin >> n >> h >> m;
    sum=n*h*h, veg=n*(h+1)+m+1;
    for (int i=1; i<=n; i++) {
        add(kezd, f, h*h);
        f++;
        for (int j=0; j<h; j++) {
            add(f-1, f, h*h-j*j);
            f++;
        }
    }
    for (int i=1; i<=m; i++) {
        int l, r, kr, ert; cin >> l >> r >> kr >> ert;
        add(f, veg, ert);
        if (kr<h) {
            for (int j=l; j<=r; j++) {
                add((j-1)*(h+1)+kr+2, f, sok);
            }
        }
        f++;
    }
    cout << sum-dinic();
    return 0;
}