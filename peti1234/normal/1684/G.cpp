#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, f, par[c];
long long t[c];
vector<int> sz[c];
bool v[c];
vector<pair<int, int> > ans;
bool dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            v[x]=true;
            if (!par[x] || dfs(par[x])) {
                par[a]=x, par[x]=a;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    f=m/3;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (t[i]>f && 2*t[i]+t[j]<=m && t[i]%t[j]==0) {
                sz[i].push_back(j);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (t[i]>f) {
            if (!dfs(i)) {
                cout << -1 << "\n";
                return 0;
            }
        }
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!par[i]) {
            ans.push_back({2*t[i], 3*t[i]});
        } else if (t[i]>f) {
            long long a=t[i], b=t[par[i]];
            ans.push_back({2*a+b, a+b});
        }
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}