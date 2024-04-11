#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int n, m, w, t[c], si[c], ki[c], kis[c], csop[c], ert[c], pos;
bool v[c];
vector<pair<int, int> > el, query;
vector<int> sz[c], uj, kapcs[c], valt[c];
priority_queue<pair<int, int> > q[c];
void dfs(int a) {
    uj.push_back(a);
    for (int i=0; i<kapcs[a].size(); i++) {
        int x=kapcs[a][i];
        dfs(x);
    }
}
int holvan(int a) {
    if (!ki[a]) return a;
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
int unio(int id) {
    int a=el[id].first, b=el[id].second;
    a=holvan(a), b=holvan(b);
    if (a==b) return 0;
    if (si[a]<si[b]) {
        si[b]+=si[a], si[a]=0, ki[a]=b;
        dfs(a);
        kapcs[b].push_back(a);
        return a;
    }
    si[a]+=si[b], si[b]=0, ki[b]=a;
    dfs(b);
    kapcs[a].push_back(b);
    return b;
}
void dfs2(int a) {
    v[a]=true, q[pos].push({ert[a], a}), csop[a]=pos;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs2(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> w;
    for (int i=1; i<=n; i++) {
        cin >> ert[i], si[i]=1;
    }
    el.push_back({0, 0}), query.push_back({0, 0});
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
        el.push_back({a, b});
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) pos++, dfs2(i);
    }
    for (int i=1; i<=n; i++) v[i]=0;
    for (int i=1; i<=w; i++) {
        int a, b; cin >> a >> b;
        query.push_back({a, b});
        if (a==2) t[b]=i;
    }
    for (int i=1; i<=m; i++) {
        if (!t[i]) unio(i);
    }
    for (int i=w; i>=1; i--) {
        int fi=query[i].first, se=query[i].second;
        if (fi==2) {
            uj.clear();
            kis[i]=unio(se);
            if (kis[i]) {
                for (int j=0; j<uj.size(); j++) valt[i].push_back(uj[j]);
                uj.clear();
            }
        }
    }
    for (int i=1; i<=w; i++) {
        int fi=query[i].first, se=query[i].second;
        if (fi==1) {
            int p=csop[se];
            while(q[p].size()>0 && p!=csop[q[p].top().second]) q[p].pop();
            if (q[p].size()>0) {
                cout << q[p].top().first << "\n";
                ert[q[p].top().second]=0;
                q[p].pop();
            } else cout << 0 << "\n";
        } else {
            if (kis[i]) {
                pos++;
                for (int j=0; j<valt[i].size(); j++) {
                    int x=valt[i][j];
                    v[x]=0, csop[x]=pos;
                    q[pos].push({ert[x], x});
                }
            }
        }
    }
    return 0;
}