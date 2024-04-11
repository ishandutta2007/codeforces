#include <bits/stdc++.h>

using namespace std;
const int c=3002;
int n, m, pos[c], si[c];
vector<int> sz[c], s[c], sol;
bool v[c], kim[c], h[c];
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<si[a]; i++) {
        int x=sz[a][i], y=s[a][i];
        if (!kim[y] && !v[x]) {
            dfs(x);
        }
    }
}
bool of(int a) {
    for (int i=1; i<=n; i++) {
        v[i]=false;
    }
    dfs(a);
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            return false;
        }
    }
    return true;
}
vector<int> uj;
vector<int> koz;
void pb(int a) {
    sol.push_back(a);
}
void dfs2(int a) {
    for ( ; pos[a]<si[a]; pos[a]++) {
        int x=sz[a][pos[a]], y=s[a][pos[a]];
        if (kim[y] || h[y]) {
            continue;
        }
        uj.push_back(x);
        pos[a]++;
        h[y]=1;
        dfs2(x);
        return;
    }
}
void Euler_ut(int a) {
    koz.push_back(a);
    while (koz.size()>0) {
        int id=koz.back();
        dfs2(id);
        koz.pop_back();
        while (uj.size()>0) {
            koz.push_back(uj.back());
            uj.pop_back();
        }
        if (pos[id]==si[id]) {
            pb(id);
        } else {
            koz.push_back(id);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), s[a].push_back(i);
        sz[b].push_back(a), s[b].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        si[i]=sz[i].size();
    }
    for (int i=1; i<=n; i++) {
        int cnt=0;
        bool baj=0;
        for (int j=1; j<=n; j++) {
            if (i!=j) {
                cnt+=si[j]%2;
            }
        }
        for (int j=1; j<=m; j++) {
            kim[j]=0;
        }
        for (int j=0; j<si[i]; j++) {
            int x=sz[i][j], y=s[i][j];
            if (si[x]%2) {
                kim[y]=1;
                cnt--;
            }
        }
        of(i);
        if (!cnt) {
            for (int j=0; j<sz[i].size(); j++) {
                int x=sz[i][j], y=s[i][j];
                if (!v[x] && kim[y] && si[x]>1) {
                    kim[y]=0;
                    break;
                }
            }
        }
        of(i);
        for (int j=1; j<=n; j++) {
            if (!v[j] && si[j]>1) {
                baj=1;
            }
        }
        if (baj || cnt>1) {
            continue;
        }
        Euler_ut(i);
        reverse(sol.begin(), sol.end());
        pb(-1);
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j], y=s[i][j];
            if (kim[y]) {
                pb(x), pb(i);
            }
        }
        break;
    }
    cout << sol.size() << "\n";
    if (sol.size()>0) {
        for (int i:sol) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}