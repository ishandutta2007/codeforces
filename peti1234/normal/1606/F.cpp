#include <bits/stdc++.h>

using namespace std;
const int c=400005, c2=1<<20, f=c/2;
int n, be[c], ki[c], fel[c], ans[c], cnt, m, m2;
int kezd[c2], veg[c2];
pair<int, int> ert[c2];
priority_queue<pair<int, int> > q;
vector<pair<pair<int, int>, int> > qu;
vector<int> sz[c];
bool v[c], valt[c];

int init(int ert) {
    int po=1;
    while (po<=ert) po*=2;
    for (int i=po; i<2*po; i++) kezd[i]=veg[i]=i-po+1;
    for (int i=po-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
}
int s(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) return 0;
    if (l<=kezd[a] && veg[a]<=r) return 2;
    return 1;
}
void add(int a, int l, int r, pair<int, int> x) {    int p=s(a, l, r);
    if (!p) return;
    if (p==2) ert[a].first+=x.first, ert[a].second+=x.second;
    if (p==1) add(2*a, l, r, x), add(2*a+1, l, r, x);
}
pair<int, int> ask(int a, int l) {
    int p=s(a, l, l);
    if (!p) return {0, 0};
    if (p==2) return ert[a];
    if (p==1) {
        pair<int, int> x=ask(2*a, l), y=ask(2*a+1, l);
        return {x.first+y.first+ert[a].first, x.second+y.second+ert[a].second};
    }
}

pair<int, int> val(int a) {
    pair<int, int> p1=ask(1, be[a]), p2=ask(1, ki[a]);
    return {p1.first-p2.first, p1.second-p2.second};
}
void pb(int a) {
    if (!a) return;
    pair<int, int> x=val(a);
    int  db=(x.first-1)/(x.second+1);
    q.push({db, a});
}
void calc() {
    int cs=qu[m2].first.second, pr=qu[m2].first.first, id=qu[m2].second;
    m2++;
    pair<int, int> x=val(cs);
    pair<int, int> rossz=ask(1, be[cs]);
    ans[id]=x.first-x.second*pr;
}

void dfs(int a) {
    v[a]=true;
    be[a]=++cnt;
    for (auto x:sz[a]) {
        if (!v[x]) {
            add(1, be[a], be[a], {1, 0});
            dfs(x);
            fel[x]=a;
        }
    }
    ki[a]=++cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    sz[0].push_back(1), sz[1].push_back(0);

    cin >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        qu.push_back({{y, x}, i});
    }
    sort(qu.rbegin(), qu.rend());


    init(2*n+2);
    dfs(0);
    for (int i=1; i<=n; i++) pb(i);
    while (q.size()>0) {
        int div=q.top().first, id=q.top().second;
        q.pop();
        if (!valt[id]) {
            valt[id]=1;
            while (m2<m && qu[m2].first.first>div) calc();
            int pos=fel[id];
            while (valt[pos]) pos=fel[pos];
            int s2=id;
            while (s2!=pos) {
                int s3=fel[s2];
                fel[s2]=pos;
                s2=s3;
            }
            pair<int, int> x=val(id);
            add(1, be[pos], be[id]-1, x);
            add(1, be[pos], be[id]-1, {-1, 1});
            pb(pos);
        }
    }
    while (m2<m) {
        calc();
    }
    for (int i=1; i<=m; i++) cout << ans[i] << "\n";
    return 0;
}