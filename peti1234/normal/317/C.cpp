#include <bits/stdc++.h>

using namespace std;
const int c=302;
int n, p, m, kezd[c], veg[c], f[c], szint[c], db[c];
vector<int> sz[c], xx, yy;
vector<pair<pair<int, int>, int> > sol;
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            f[x]=a;
            dfs(x);
        }
    }
}
int lca(int a, int b) {
    while(szint[a]>szint[b]) {
        a=f[a];
    }
    while(szint[b]>szint[a]) {
        b=f[b];
    }
    while(a!=b) {
        a=f[a], b=f[b];
    }
    return a;
}
void add(int a, int b, int c) {
    if (!c) {
        return;
    }
    sol.push_back({{a, b}, c});
    kezd[a]-=c, kezd[b]+=c, db[a]+=c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> m;
    for (int i=1; i<=n; i++) {
        cin >> kezd[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> veg[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            szint[i]=1, dfs(i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int a=i, b=j, ert=min(kezd[a]-veg[a], veg[b]-kezd[b]), s=lca(a, b);
            if (ert>0 && s) {
                xx.clear(), yy.clear();
                for (int k=0; k<=n; k++) {
                    db[k]=0;
                }
                while(a!=s) {
                    xx.push_back(a);
                    a=f[a];
                }
                xx.push_back(a);
                while(b!=s) {
                    yy.push_back(b);
                    b=f[b];
                }
                reverse(yy.begin(), yy.end());
                for (int i:yy) {
                    xx.push_back(i);
                }
                int si=xx.size();
                for (int i=si-2; i>=0; i--) {
                    int a=xx[i], b=xx[i+1];
                    add(a, b, min({ert, kezd[a], p-kezd[b]}));
                }
                for (int i=0; i<si-1; i++) {
                    int a=xx[i], b=xx[i+1];
                    add(a, b, ert-db[a]);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (kezd[i]!=veg[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << sol.size() << "\n";
    for (auto i:sol) {
        cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
    }
    return 0;
}
/*
7 7 5
0 0 0 7 0 7 7
0 0 7 7 7 0 0
1 2
4 3
4 5
4 6
4 7
*/