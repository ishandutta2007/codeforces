#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, p[c], fel[c], szint[c];
vector<int> sz[c], sz2[c], sor;
bool v[c], v2[c];
map<pair<int, int>, int> id;
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
        }
    }
}
void dfs2(int a) {
    v2[a]=true;
    for (auto x:sz2[a]) {
        if (!v2[x]) {
            dfs2(x);
        }
    }
    sor.push_back(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if (a>b) swap(a, b);
        id[{a, b}]=i;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            szint[i]=1;
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++) {
        int kezd=i, veg=p[i];
        vector<int> x, y;
        while (kezd!=veg) {
            if (szint[kezd]>szint[veg]) {
                x.push_back(kezd);
                kezd=fel[kezd];
            } else {
                y.push_back(veg);
                veg=fel[veg];
            }
        }
        x.push_back(kezd);
        reverse(y.begin(), y.end());
        for (auto p:y) {
            x.push_back(p);
        }
        int si=x.size();
        for (int i=1; i<si-1; i++) {
            int a=x[i-1], b=x[i], c=x[i+1];
            int ab=(a<b ? id[{a, b}] : id[{b, a}]), bc=(b<c ? id[{b, c}] : id[{c, b}]);
            sz2[bc].push_back(ab);
        }
    }
    for (int i=1; i<=m; i++) {
        if (!v2[i]) {
            dfs2(i);
        }
    }
    for (auto x:sor) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}