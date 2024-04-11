#include <bits/stdc++.h>

using namespace std;
const int c=50002;
vector<int> sz[c];
int n, q, t[c], f[c], k[c], be[c], ki[c], r[c], sa[c], da[c], cnt, p, sum, db;
vector<pair<int, int> > s;
void dfs(int a, int b) {
    be[a]=cnt;
    k[a]=b;
    if (t[a]==1) sa[a]+=b, da[a]++;
    else cnt++;
    for (int i:sz[a]) {
        dfs(i, b+1);
        sa[a]+=sa[i], da[a]+=da[i];
    }
    ki[a]=cnt;
    if (t[a]!=1) s.push_back({be[a], a});
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=2; i<=n; i++) {
        int x; cin >> x;
        sz[x].push_back(i);
    }
    dfs(1, 0);
    sort(s.begin(), s.end());
    for (int i=0; i<cnt; i++) r[i]=s[i].second;
    while(p<q) {
        int x; cin >> x;
        sum=sa[x], db=da[x];
        for (int i=be[x]; i<ki[x]; i++) {
            int a=r[i];
            if (f[a]<=p) {
                sum+=k[a], db++;
                f[a]=p+t[a];
            }
        }
        cout << sum-db*k[x] << " " << db << "\n";
        p++;
    }
    return 0;
}