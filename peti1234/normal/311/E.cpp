#include <bits/stdc++.h>

using namespace std;
const int c=12002;

int n, m, g, s1[c], s2[c];

int kezd, veg, pos[c], szint[c];
long long sum;

long long sok=1e12;
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
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> g, veg=n+m+1;
    for (int i=1; i<=n; i++) {
        cin >> s1[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> s2[i];
        if (s1[i]==0) {
            add(i, veg, s2[i]);
        } else {
            add(kezd, i, s2[i]);
        }
    }
    for (int i=1; i<=m; i++) {
        bool v, fr;
        int pl, db, x;
        cin >> v >> pl >> db;

        sum+=pl;
        for (int j=1; j<=db; j++) {
            cin >> x;
            if (v==0) {
                add(x, n+i, sok);
            } else {
               add(n+i, x, sok);
            }
        }
        cin >> fr;
        if (v==0) {
            add(n+i, veg, pl+fr*g);
        } else {
            add(kezd, n+i, pl+fr*g);
        }
    }
    cout << sum-dinic() << "\n";

    return 0;
}