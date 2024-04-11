#include <bits/stdc++.h>

using namespace std;
const int c=102, cc=1002, sok=1e7;
int n, m, kezd, veg, cs1[cc], cs2[cc], pl[cc];
vector<int> sz[c], kap[c];
int bal[c];
bool fv[c];
vector<int> fsz[c], fs[c], finv[c];
bool fdfs(int a) {
    fv[a]=1;
    if (a==veg) {
        return true;
    }
    for (int i=0; i<fsz[a].size(); i++) {
        int x=fsz[a][i], y=fs[a][i], inv=finv[a][i];
        if (y && !fv[x]) {
            if (fdfs(x)) {
                fs[a][i]--;
                fs[x][inv]++;
                return true;
            }
        }
    }
    return false;
}
int flow() {
    int ans=0;
    while (fdfs(kezd)) {
        ans++;
        for (int i=1; i<=n; i++) {
            fv[i]=0;
        }
    }
    return ans;
}
bool v[c];
bool dfs(int a) {
    v[a]=true;
    if (bal[a]>0) {
        return true;
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            if (dfs(x)) {
                kap[a][i]++;
                bal[a]++, bal[x]--;
                return true;
            }
        }
    }
    return false;
}
int bal2[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> kezd >> veg;
    for (int i=1; i<=m; i++) {
        int a, b, fl;
        cin >> a >> b >> fl;
        cs1[i]=a, cs2[i]=b, pl[i]=fl;
        finv[a].push_back(fsz[b].size()), finv[b].push_back(fsz[a].size());
        fsz[a].push_back(b), fsz[b].push_back(a);
        fs[a].push_back((fl ? 1 : sok)), fs[b].push_back((fl ? sok : 0));
        if (fl) {
            sz[a].push_back(b), kap[a].push_back(1);
            bal[a]++, bal[b]--;
        }
    }

    cout << flow() << "\n";
    bal[kezd]=-sok, bal[veg]=sok;
    for (int i=1; i<=n; i++) {
        if (i==kezd || i==veg) {
            continue;
        }
        while (bal[i]<0) {
            for (int j=1; j<=n; j++) {
                v[j]=0;
            }
            dfs(i);
        }
    }
    bal[veg]=-sok;
    for (int i=1; i<=n; i++) {
        if (i==kezd || i==veg) {
            continue;
        }
        while (bal[i]>0) {
            for (int j=1; j<=n; j++) {
                v[j]=0;
            }
            dfs(kezd);
        }
    }
    for (int i=1; i<=m; i++) {
        int a=cs1[i], b=cs2[i], add=pl[i];
        if (!add) {
            cout << 0 << " " << 1 << "\n";
        } else {
            int spec=(!fv[a] || fv[b]);
            for (int j=0; j<sz[a].size(); j++) {
                if (b==sz[a][j]) {
                    bal2[a]+=kap[a][j], bal2[b]-=kap[a][j];
                    cout << kap[a][j] << " " << kap[a][j]+spec << "\n";
                }
            }
        }
    }

    return 0;
}