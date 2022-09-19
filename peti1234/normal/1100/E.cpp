#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<pair<int, int>, pair <int, int>>> v;
int e[100001];
vector<int> sz[100001];
vector<int> k;
int w[100001];
int x=-1, y=1000000002;
bool dfs(int a)
{
    w[a]=2;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (w[x]==2) {
            return false;
        }
        if (w[x]==0) {
           bool c=dfs(x);
           if (!c) {
            return false;
           }
        }
        e[a]=max(e[a], e[x]+1);
    }
    w[a]=1;
    return true;
}
bool ker(int z)
{
    for (int i=0; i<=n; i++) {
        w[i]=0;
        e[i]=0;
        sz[i].clear();
    }
    for (int i=0; i<v.size(); i++) {
        if (-v[i].first.first>=z) {
            sz[v[i].second.first].push_back(v[i].second.second);
        }
    }
    for (int i=1; i<=n; i++) {
        if (w[i]==0) {
            bool c=true;
            c=dfs(i);
            if (!c) {
                return false;
            }
        }
    }
    k.clear();
    for (int i=0; i<v.size(); i++) {
        int sf=v[i].second.first;
        int ss=v[i].second.second;
        if ((e[sf]<e[ss])|| (e[sf]==e[ss] && sf>ss)) {
            k.push_back(v[i].first.second);
            if (e[sf]==e[ss]) {
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{-c, i},{a, b}});
    }
    while(y-x>1) {
        int z=(x+y)/2;
        if (ker(z)) {
            y=z;
        } else {
            x=z;
        }
    }
    if (y>1) {
        y--;
    }
    cout << y << " " << k.size() << endl;
    for (int i=0; i<k.size(); i++) {
        cout << k[i] << " ";
    }
    return 0;
}
/*
5 10
1 2 1000000000
1 3 1000000000
3 2 1000000000
4 2 1000000000
2 5 1000000000
1 4 1000000000
1 5 1000000000
4 3 1000000000
5 3 1000000000
4 5 1000000000
*/