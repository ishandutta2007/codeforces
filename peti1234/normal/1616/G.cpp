#include <bits/stdc++.h>

using namespace std;
const int c=300105;
int w, n, n2, m, jo[c], kov[c];
vector<int> l[c], sz[c][2];
bool v[c][2];
void dfs(int a, int b) {
    v[a][b]=true;
    for (auto x:sz[a][b]) {
        if (!v[x][b]) {
            dfs(x, b);
        }
    }
}
void add(int a, int b) {
    sz[a][0].push_back(b+n2);
    sz[a+n2][0].push_back(b);
    sz[b][1].push_back(a+n2);
    sz[b+n2][1].push_back(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        n2=n+5;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            if (b==a+1) {
                jo[a]=1;
            } else {
                l[a].push_back(b);
            }
        }
        for (int i=n; i>=1; i--) {
            kov[i]=(jo[i] ? kov[i+1] : i);
            for (auto x:l[i]) {
                if (kov[i+1]>=x-1) {
                    add(i, x-1);
                }
            }
            if (kov[i]==n) {
                add(i-1, n);
            }
        }

        if (kov[1]==n) {
            cout << (long long) n*(n-1)/2 << "\n";
        } else {
            int kezd=kov[1], veg=0;
            for (int i=1; i<=kezd; i++) {
                add(0, i);
            }
            for (int i=1; i<=n; i++) {
                if (kov[i]!=n) {
                    veg=i;
                }
            }
            dfs(kezd, 0), dfs(kezd, 1);
            long long ka=0, kb=0, kc=0, va=0, vb=0, vc=0;
            for (int i=0; i<=n; i++) {
                if (i<=kezd) {
                    if (v[i][1]) ka++;
                    if (v[i+n2][1]) kb++;
                    if (v[i][1] && v[i+n2][1]) kc++;
                }
                if (i>=veg) {
                    if (v[i][0]) va++;
                    if (v[i+n2][0]) vb++;
                    if (v[i][0] && v[i+n2][0]) vc++;
                }
            }
            cout << ka*va+kb*vb-kc*vc-(kezd==veg) << "\n";
        }
        for (int i=0; i<=2*n2; i++) {
            jo[i]=0, kov[i]=0;
            v[i][0]=0, v[i][1]=0;
            l[i].clear();
            sz[i][0].clear(), sz[i][1].clear();
        }
    }
    return 0;
}