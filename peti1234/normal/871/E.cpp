#include <bits/stdc++.h>

using namespace std;
const int c=30005, c2=205;
int n, k, fel[c], x[c], y[c], tav[c][c2], cel[c], dist[c], szint[c], pos;
bool v[c], kesz[c];
vector<int> sz[c];
vector<pair<int, int> > ans;
map<pair<int, int>, int> m;
void baj() {
    cout << -1 << "\n";
    exit(0);
}
void pb(int a, int b) {
    sz[a].push_back(b), sz[b].push_back(a);
    ans.push_back({a, b});
}
void dfs(int a, int b) {
    v[a]=true;
    if (szint[a]!=tav[a][b]) {
        cout << "baj " << a << " " << b << " " << szint[a] << " " << tav[a][b] << "\n";
        baj();
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x, b);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        tav[i][1]=x[i];
        if (!x[i]) {
            tav[0][1]=i;
            pos=i;
        }
    }
    if (!pos) {
        baj();
    }
    kesz[pos]=1;
    for (int i=1; i<=n; i++) {
        if (i!=pos) {
            dist[i]=x[i];
            cel[i]=pos;
        }
    }
    for (int j=2; j<=k; j++) {
        vector<pair<int, int> > sz;
        for (int i=1; i<=n; i++) {
            cin >> y[i];
            tav[i][j]=y[i];
            if (!y[i]) {
                tav[0][j]=i;
            }
        }
        if (!tav[0][j]) {
            baj();
        }
        int d=y[pos];
        for (int i=1; i<=n; i++) {
            if (x[i]+y[i]==d) {
                sz.push_back({x[i], i});
            }
        }
        if (sz.size()!=d+1) {
            baj();
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<=d; i++) {
            int a=sz[i].second;
            fel[a]=sz[i-1].second;
            kesz[a]=1;
        }
        for (int i=1; i<=n; i++) {
            int add=(x[i]+y[i]-d)/2;
            if (add<0 || add>x[i]) {
                baj();
            }
            if (add<dist[i]) {
                dist[i]=add;
                cel[i]=sz[x[i]-add].second;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!kesz[i]) {
            m[{cel[i], dist[i]}]=i;
        }
    }
    for (int i=1; i<=n; i++) {
        if (i==pos) {
            continue;
        }
        if (kesz[i]) {
            pb(i, fel[i]);
        } else {
            int x=(dist[i]>1 ? m[{cel[i], dist[i]-1}] : cel[i]);
            if (!x) {
                baj();
            }
            pb(i, x);
        }
    }

    for (int j=1; j<=k; j++) {
        for (int i=1; i<=n; i++) {
            v[i]=0;
            szint[i]=0;
        }
        dfs(tav[0][j], j);
    }

    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}