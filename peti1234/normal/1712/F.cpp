#include <bits/stdc++.h>

using namespace std;

const int c=1000005, k=20;
int n, szint[c], fel[c][k];
vector<int> sz[c];
bool v[c], vis[c];

void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=(fel[fel[a][i-1]][i-1]);
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) swap(a, b);
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) a=fel[a][i];
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a==b) return a;
    return fel[a][0];
}
int tav(int a, int b) {
    return szint[a]+szint[b]-2*szint[lca(a, b)];
}

queue<int> q;
int dist[c], si[c];
vector<int> level[c], fontos;

bool spec[c];

int diam, cs1=1, cs2=1;
bool vv[c];
pair<int, int> diam_dfs(int a) {
    vv[a]=true;
    pair<int, int> p1={0, a}, p2={0, a};
    if (!spec[a]) {
        p1={-c, a}, p2={-c, a};
    }
    for (auto x:sz[a]) {
        if (!vv[x]) {
            p2=max(p2, diam_dfs(x));
            if (p2>p1) swap(p1, p2);
        }
    }
    if (p1.first+p2.first>diam) {
        diam=p1.first+p2.first, cs1=p1.second, cs2=p2.second;
    }
    p1.first++;
    return p1;
}
void calc_diam(vector<int> p) {
    for (auto x:p) spec[x]=1;
    diam=0, cs1=0, cs2=0;
    pair<int, int> g=diam_dfs(1);
    assert(cs1), assert(cs2);
    fontos.push_back(cs1), fontos.push_back(cs2);
    for (int i=1; i<=n; i++) {
        vv[i]=0;
    }
    for (auto x:p) spec[x]=0;

}


int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        int p;
        cin >> p;
        sz[p].push_back(i);
        sz[i].push_back(p);
    }
    szint[1]=1;
    dfs(1);

    for (int i=1; i<=n; i++) {
        si[i]=sz[i].size();
        if (si[i]==1) {
            q.push(i);
            vis[i]=true;
        }
    }
    while (q.size()>0) {
        int a=q.front();
        q.pop();
        for (auto x:sz[a]) {
            if (!vis[x]) {
                vis[x]=1;
                dist[x]=dist[a]+1;
                q.push(x);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        int maxi=0;
        for (auto x:sz[i]) {
            maxi=max(maxi, dist[x]);
        }
        if (dist[i]>=maxi) {
            level[dist[i]].push_back(i);
        }
    }

    for (int i=0; i<=n; i++) {
        int cnt=level[i].size();
        if (cnt==0) continue;
        if (cnt<=1) {
            for (auto x:level[i]) {
                fontos.push_back(x);
            }
        } else if (cnt<=500) {
            int x=0, y=0, maxi=0;
            for (int j=0; j<cnt; j++) {
                for (int k=j+1; k<cnt; k++) {
                    int a=level[i][j], b=level[i][k], t=tav(a, b);
                    if (t>maxi) {
                        maxi=t, x=a, y=b;
                    }
                }
            }
            fontos.push_back(x), fontos.push_back(y);
        } else {
            calc_diam(level[i]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int maxi=0, cnt=fontos.size();
        for (int i=0; i<cnt; i++) {
            for (int j=i; j<cnt; j++) {
                int a=fontos[i], b=fontos[j];
                int t=tav(a, b), add=dist[a]+dist[b];
                maxi=max(maxi, min({(x+t+add)/2, t+add, x+add}));
            }
        }
        cout << maxi << " ";
    }

    return 0;
}