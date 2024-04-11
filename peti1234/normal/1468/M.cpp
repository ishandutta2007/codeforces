#include<bits/stdc++.h>

using namespace std;
const int c=200002, gy=400;
int w, n, m, cnt[c], ki[c];
bool v[c];
vector<int> sz[c], s[c], h;
map<int, int> p;
void solve() {
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>=gy) {
            for (int j=1; j<=m; j++) {
                v[j]=0;
            }
            for (int j:sz[i]) {
                v[j]=1;
            }
            for (int j=1; j<=n; j++) {
                if (i==j) {
                    continue;
                }
                cnt[j]=0;
                for (int k:sz[j]) {
                    if (v[k]) {
                        cnt[j]++;
                    }
                }
                if (cnt[j]>1) {
                    cout << i << " " << j << "\n";
                    return;
                }
            }
        }
    }
    for (int j=1; j<=m; j++) {
        for (int i:h) {
            ki[i]=0;
        }
        h.clear();
        for (int i:s[j]) {
            if (sz[i].size()<gy) {
                for (int k:sz[i]) {
                    if (k==j) {
                        continue;
                    }
                    if (ki[k]) {
                        cout << i << " " << ki[k] << "\n";
                        return;
                    }
                    ki[k]=i;
                    h.push_back(k);
                }
            }
        }
    }
    cout << -1 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, p.clear(), m=0;
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            int x; cin >> x;
            for (int j=1; j<=x; j++) {
                int y; cin >> y;
                if (!p[y]) {
                    m++;
                    s[m].clear();
                    p[y]=m;
                }
                y=p[y];
                sz[i].push_back(y), s[y].push_back(i);
            }
        }
        solve();
    }
    return 0;
}