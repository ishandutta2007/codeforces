#include <bits/stdc++.h>

using namespace std;
const int c=3002, sok=2e8;
int sum, n, aa[c], bb[c];
bool ss[102];

int kezd, veg, pos[c], szint[c];
vector<int> sz[c], ki[c];
vector<int> s[c];
void add(int a, int b, int c) {
    //cout << "el " << a << " " << b << " " << c << "\n";
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
    ios_base::sync_with_stdio(false);
    cin >> n, veg=n+1;
    for (int i=1; i<=n; i++) {
        cin >> aa[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> bb[i];
        if (bb[i]<0) {
            add(i, veg, -bb[i]);
        } else {
            add(kezd, i, bb[i]);
            sum+=bb[i];
        }
        for (int j=i-1; j>=1; j--) {
            if (aa[i]%aa[j]==0 && !ss[aa[j]]) {
                add(i, j, sok);
                ss[aa[j]]=1;
            }
        }
        for (int i=1; i<=100; i++) {
            ss[i]=0;
        }
    }
    cout << sum-dinic() << "\n";
    return 0;
}