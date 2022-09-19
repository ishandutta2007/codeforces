#include <bits/stdc++.h>

using namespace std;
const int c=30002, sok=2e9+1;
int n, m, st, fi, cnt, si, eler[c], visz[c], f[c], suly[c], sum, mini=sok, u1, u2, til, el;
vector<int> sz[c], id[c], ut;
bool v1[c], v2[c], v3[c], elv[c];
bool dfs1(int a) {
    v1[a]=true;
    if (a==fi) return true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=id[a][i];
        if (!v1[x]) {
            if (dfs1(x)) {
                ut.push_back(y);
                return true;
            }
        }
    }
    return false;
}
void dfs2(int a) {
    v2[a]=true;
    cnt++, eler[a]=cnt, visz[a]=cnt;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=id[a][i];
        if (y!=til) {
            if (!v2[x]) {
                f[x]=y;
                dfs2(x);
                if (eler[x]==visz[x]) {
                    elv[y]=1;
                }
                visz[a]=min(visz[a], visz[x]);
            } else if (y!=f[a]) {
                visz[a]=min(visz[a], eler[x]);
            }
        }
    }
}
bool dfs3(int a) {
    v3[a]=true;
    if (a==fi) return true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=id[a][i];
        if (y!=til) {
            if (!v3[x]) {
                if (dfs3(x)) {
                    if (elv[y]) {
                        if (!el || suly[y]<suly[el]) {
                            el=y;
                        }
                    }
                    return true;
                }

            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> st >> fi;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a);
        id[a].push_back(i), id[b].push_back(i);
        suly[i]=c;
    }
    dfs1(st);
    si=ut.size();
    if (!si) {
        cout << "0\n0\n\n";
        return 0;
    }
    for (int i=0; i<si; i++) {
        til=ut[i];
        el=0, cnt=0;
        for (int i=1; i<=n; i++) {
            v2[i]=0, v3[i]=0, eler[i]=0, visz[i]=0, f[i]=0;
        }
        for (int i=1; i<=m; i++) elv[i]=0;
        dfs2(st);
        dfs3(st);
        sum=suly[til]+suly[el];
        if (!v3[fi] || el) {
            if (sum<mini) {
                mini=sum;
                u1=til, u2=el;
            }
        }
    }
    if (!u1) {
        cout << "-1\n";
        return 0;
    }
    cout << mini << "\n";
    cout << (u1!=0)+(u2!=0) << "\n";
    if (u1) cout << u1 << " ";
    if (u2) cout << u2 << " ";
    cout << "\n";
    return 0;
}