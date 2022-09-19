#include <bits/stdc++.h>

using namespace std;
const int c=200002, cc=20;
int n, w;

int cnt, eler[c], szint[c], fel[c][cc];
vector<int> sz[c];
bool v[c];

int k, m, kezd[c], seb[c], sor[c], ans[c];
set<pair<int, int> > alap, fontos;
vector<int> ut;
vector<int> sz2[c];
priority_queue<pair<pair<int, int>, int> > q;
bool v2[c];

void dfs(int a) {
    v[a]=true;
    eler[a]=++cnt;
    for (int i=1; i<cc; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=cc-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    if (a==b) {
        return a;
    }
    for (int i=cc-1; i>=0; i--) {
        int aa=fel[a][i], bb=fel[b][i];
        if (aa!=bb) {
            a=aa, b=bb;
        }
    }
    return fel[a][0];
}
int tav(int a, int b) {
    return szint[a]+szint[b]-2*szint[lca(a, b)];
}
bool felett(int a, int b) {
    return (a==lca(a, b));
}
pair<int, int> cs(int a) {
    return {eler[a], a};
}
void add(int dist, int id, int cs) {
    q.push({{-dist, -id}, cs});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    cin >> w;
    while (w--) {
        cin >> k >> m;
        for (int i=1; i<=k; i++) {
            cin >> kezd[i] >> seb[i];
            alap.insert(cs(kezd[i]));
        }
        for (int i=1; i<=m; i++) {
            cin >> sor[i];
            alap.insert(cs(sor[i]));
        }
        int el=0;
        for (auto xx:alap) {
            int x=xx.second;
            if (el) {
                int uj=lca(el, x);
                fontos.insert(cs(uj));
            }
            fontos.insert(cs(x));
            el=x;
        }
        for (auto xx:fontos) {
            int x=xx.second;
            while (ut.size()>0 && !felett(ut.back(), x)) {
                ut.pop_back();
            }
            if (ut.size()>0) {
                int cs=ut.back();
                sz2[x].push_back(cs), sz2[cs].push_back(x);
            }
            ut.push_back(x);
        }
        for (int i=1; i<=k; i++) {
            add(0, i, kezd[i]);
        }
        while (q.size()>0) {
            int id=-q.top().first.second, a=q.top().second;
            q.pop();
            if (!v2[a]) {
                v2[a]=true;
                ans[a]=id;
                for (int x:sz2[a]) {
                    if (!v2[x]) {
                        int ido=(tav(kezd[id], x)+seb[id]-1)/seb[id];
                        add(ido, id, x);
                    }
                }
            }
        }
        for (int i=1; i<=m; i++) {
            cout << ans[sor[i]] << " ";
        }
        cout << "\n";
        for (auto xx:fontos) {
            int x=xx.second;
            sz2[x].clear(), v2[x]=0;
        }
        alap.clear(), fontos.clear(), ut.clear();
    }
    return 0;
}