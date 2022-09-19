#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, dist[c][c];
vector<int> sz[c], s[c], l;
bool v[c];
vector<pair<int, pair<int ,int > > > t;
void bfs(int a, int f)
{
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (dist[x][f]==0) {
            dist[x][f]=dist[a][f]+1;
            bfs(x, f);
        }
    }
}
void solve(int a, int b, int y)
{
    if (y==0) {
        return;
    }
    if (sz[a].size()==1) {
        swap(a, b);
    }
    if (sz[a].size()==1) {
        t.push_back({a, {b, y}});
        return;
    }
    int esz, msz, besz=0, bmsz=0;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (x!=b) {
            esz=x;
            swap(esz, msz);
        }
    }
    int c, d, e, f;
    if (sz[b].size()==1) {
        e=b;
        f=b;
    } else {
        for (int i=0; i<sz[b].size(); i++) {
            int x=sz[b][i];
            if (x!=a) {
                besz=x;
                swap(besz, bmsz);
            }
        }
    }
    for (int i=0; i<l.size(); i++) {
        int x=l[i];
        if (dist[a][x]<dist[b][x]) {
            if (dist[esz][x]<dist[msz][x]) {
                c=x;
            } else {
                d=x;
            }
        } else {
            if (besz!=0) {
                if (dist[besz][x]<dist[bmsz][x]) {
                    e=x;
                } else {
                    f=x;
                }
            } else {
            e   =x;
                swap(e, f);
            }
        }
    }
    y/=2;
    t.push_back({c,{e, y}});
    t.push_back({d,{f, y}});
    t.push_back({c,{d, -y}});
    if (e!=f) {
        t.push_back({e,{f, -y}});
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b);
        sz[b].push_back(a);
        s[a].push_back(c);
        s[b].push_back(c);
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()==2) {
            cout << "NO";
            return 0;
        }
        if (sz[i].size()==1) {
            l.push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        dist[i][i]=1;
        bfs(i, i);
    }
    cout << "YES" << "\n";
    for (int i=1; i<=n; i++) {
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j];
            int y=s[i][j];
            if (i<x) {
                solve(i, x, y);
            }
        }
    }
    cout << t.size() << "\n";
    for (int i=0; i<t.size(); i++) {
        cout << t[i].first << " " << t[i].second.first << " " << t[i].second.second << "\n";
    }
    return 0;
}