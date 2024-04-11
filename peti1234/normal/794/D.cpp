#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long s[c], t[c], db[c], ert[c], ki[c], cnt, n, m, pos, f, sok=1e18;
bool baj;
vector<int> sz[c];
vector<pair<long long, int> > k;
void dfs(int a) {
    ert[a]=++cnt;
    for (int x:sz[a]) {
        if (!ert[x] && ki[x]==x) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        s[i]=uniform_int_distribution<long long>(1, sok)(rng);
        t[i]+=s[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        t[a]+=s[b], t[b]+=s[a], t[a]%=sok, t[b]%=sok;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        ki[i]=i;
        k.push_back({t[i], i});
    }
    sort(k.begin(), k.end());
    for (int i=1; i<n; i++) {
        if (k[i].first==k[i-1].first) {
            ki[k[i].second]=ki[k[i-1].second];
        }
    }
    for (int i=1; i<=n; i++) {
        if (ki[i]==i) {
            for (int j:sz[i]) {
                if (ki[j]==j) {
                    db[i]++;
                }
            }
            if (db[i]>2) {
                baj=1;
            }
            if (db[i]==2) {
                f++;
            }
            if (db[i]==1) {
                pos=i;
            }
        }
    }
    if (f && !pos) {
        baj=1;
    }
    if (baj) {
        cout << "NO\n";
    } else {
        if (!pos) {
            pos=1;
        }
        dfs(pos);
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            cout << ert[ki[i]] << " ";
        }
        cout << "\n";
    }
    return 0;
}