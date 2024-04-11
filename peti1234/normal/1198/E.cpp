#include <bits/stdc++.h>

using namespace std;
int m, n, kom[102][102], xsi, ysi;
vector<pair<pair<int, int>, pair<int, int> > > ss;
vector<int> x, y, xx, yy;
int xki(int a) {
    for (int i=0; i<xsi; i++) {
        if (xx[i]==a) {
            return i;
        }
    }
}
int yki(int a) {
    for (int i=0; i<ysi; i++) {
        if (yy[i]==a) {
            return i;
        }
    }
}


const int c=2002;
int kezd, veg, pos[c], szint[c];
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
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c, d; cin >> a >> c >> b >> d;
        b++, d++;
        x.push_back(a), x.push_back(b), y.push_back(c), y.push_back(d);
        ss.push_back({{a, b}, {c, d}});
    }
    x.push_back(0), y.push_back(0);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i=0; i<x.size(); i++) {
        if (!i || x[i]!=x[i-1]) {
            xx.push_back(x[i]);
        }
    }
    for (int i=0; i<y.size(); i++) {
        if (!i || y[i]!=y[i-1]) {
            yy.push_back(y[i]);
        }
    }
    xsi=xx.size(), ysi=yy.size();
    veg=xsi+ysi+1;
    for (int i=0; i<n; i++) {
        int a=ss[i].first.first, b=ss[i].first.second, c=ss[i].second.first, d=ss[i].second.second;
        int aa=xki(a), bb=xki(b), cc=yki(c), dd=yki(d);
        kom[aa][cc]++, kom[aa][dd]--, kom[bb][cc]--, kom[bb][dd]++;
    }
    for (int i=2; i<xsi; i++) {
        add(kezd, i-1, xx[i]-xx[i-1]);
    }
    for (int i=2; i<ysi; i++) {
        add(xsi+i-1, veg, yy[i]-yy[i-1]);
    }
    for (int i=1; i<=xsi; i++) {
        for (int j=1; j<=ysi; j++) {
            kom[i][j]+=kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1];
            if (kom[i][j]) {
                add(i, xsi+j, sok);
            }
        }
    }
    cout << dinic() << "\n";
    return 0;
}
/*
10 2
4 1 5 10
1 4 10 5
*/