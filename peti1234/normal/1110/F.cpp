#include <bits/stdc++.h>

using namespace std;
const int k=(1<<20), c=k/2;
long long n, q, ans[c], dist[c], ut[c], cnt, po=1;
long long kezd[k], veg[k], mini[k], lp[k], sok=1e17;
vector<pair<int, int> > sz[c];
vector<pair<pair<int, int>, int> > kerd[c];
void add(int a, int l, int r, long long ert) {
    int bal=kezd[a], jobb=veg[a];
    if (bal>r || jobb<l) {
        return;
    }
    if (l<=bal && jobb<=r) {
        lp[a]+=ert;
        return;
    }
    int x=2*a, y=2*a+1;
    add(x, l, r, ert), add(y, l, r, ert);
    mini[a]=min(mini[x]+lp[x], mini[y]+lp[y]);
}
long long ask(int a, int l, int r) {
    int bal=kezd[a], jobb=veg[a];
    if (bal>r || jobb<l) {
        return sok;
    }
    if (l<=bal && jobb<=r) {
        return mini[a]+lp[a];
    }
    int x=2*a, y=2*a+1;
    lp[x]+=lp[a], lp[y]+=lp[a];
    lp[a]=0;
    mini[a]=min(mini[x]+lp[x], mini[y]+lp[y]);
    return min(ask(x, l, r), ask(y, l, r));
}
void init(int po) {
    for (int i=po; i<2*po; i++) {
        kezd[i]=veg[i]=i-po+1;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i];
        veg[i]=veg[2*i+1];
    }
}
void dfs(int a) {
    cnt++;
    for (auto x:sz[a]) {
        int fi=x.first, se=x.second;
        dist[fi]=dist[a]+se;
        dfs(fi);
    }
    ut[a]=cnt;
    long long ert=dist[a];
    if (sz[a].size()>0) {
        ert=sok;
    }
    add(1, a, a, ert);
}
void dfs2(int a) {
    for (auto p:kerd[a]) {
        int l=p.first.first, r=p.first.second, id=p.second;
        ans[id]=ask(1, l, r);
    }
    for (auto x:sz[a]) {
        int fi=x.first, se=x.second;
        add(1, 1, n, se);
        add(1, fi, ut[fi], -2*se);
        dfs2(fi);
        add(1, 1, n, -se);
        add(1, fi, ut[fi], 2*se);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    while (po<n) {
        po*=2;
    }
    init(po);
    for (int i=2; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back({i, b});
    }
    dfs(1);
    for (int i=1; i<=q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        kerd[a].push_back({{b, c}, i});
    }
    dfs2(1);
    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}