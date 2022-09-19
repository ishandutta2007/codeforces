#include <bits/stdc++.h>

using namespace std;
const int c=(1<<14), k=15;
int n, m, dp[c][k][k], po[k], t[k];
pair<int, int> ans[c][k][k], ki[c][k][k];
vector<int> sz[k];
vector<pair<int, int> > f, r, res;
bool el[k][k], v[k];
void valt(int a, int b, int c, int d, int s1, int s2, int h1, int h2, int h3) {
    if (s1>s2) {
        swap(s1, s2);
    }
    if (!dp[a][b][c] || dp[a][b][c]>d) {
        dp[a][b][c]=d;
        ans[a][b][c]={s1, s2};
        ki[a][b][c]={h1, h2*k+h3};
    }
}
void dfs(int a, int b) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x] && x!=b) {
            dfs(x, b);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        el[a][b]=1, el[b][a]=1;
    }
    po[1]=1, t[n]=2;
    for (int i=2; i<=n; i++) {
        po[i]=po[i-1]*2;
    }
    for (int i=1; i<n; i++) {
        if (el[i][n]) {
            valt(po[i], i, n, 1, n, i, 0, 0, 0);
        }
    }


    for (int mask=1; mask<po[n]; mask++) {
        int s=mask, uj=0;
        for (int i=1; i<n; i++) {
            t[i]=s%2;
            s/=2;
        }
        for (int a=1; a<=n; a++) {
            for (int b=1; b<=n; b++) {
                int ert=dp[mask][a][b];
                if (!ert) {
                    continue;
                }
                for (int i=1; i<=n; i++) {
                    if (el[a][i]) {
                        if (!t[i]) {
                            valt(mask+po[i], i, b, ert+1, a, i, mask, a, b);
                        }
                    }
                }
                if (el[a][b]) {
                    valt(mask, 0, 0, ert+1, a, b, mask, a, b);
                }
            }
        }

        if (dp[mask][0][0]) {
            for (int a=1; a<=n; a++) {
                for (int b=1; b<=n; b++) {
                    for (int c=1; c<=n; c++) {
                        if (t[a] && t[b] && !t[c] && el[a][c]) {
                            valt(mask+po[c], c, b, dp[mask][0][0]+1, a, c, mask, 0, 0);
                        }
                    }
                }
            }
        }
    }
    cout << dp[po[n]-1][0][0] << "\n";
    int a=po[n]-1, b=0, c=0;
    while (a) {
        f.push_back(ans[a][b][c]);
        int s=ki[a][b][c].second;
        a=ki[a][b][c].first, b=s/k, c=s%k;
    }
    sort(f.begin(), f.end());
    for (int i=0; i<f.size(); i++) {
        int a=f[i].first, b=f[i].second;
        el[a][b]=0, el[b][a]=0;
        if (i==0 || f[i]!=f[i-1]) {
            sz[a].push_back(b), sz[b].push_back(a);
            res.push_back(f[i]);
        } else {
            r.push_back(f[i]);
        }
    }
    for (auto x:r) {
        int a=x.first, b=x.second;
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
        dfs(a, b);
        bool jo=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (el[i][j] && v[i] && !v[j] && !jo) {
                    res.push_back({i, j});
                    jo=1;
                }
            }
        }
    }
    for (auto x:res) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}