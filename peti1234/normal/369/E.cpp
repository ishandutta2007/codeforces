#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, m, db, t[c], sol[c];
vector<pair<pair<int, int>, pair<int, int> > > sz;
int lsb(int a) {
    return (a&(-a));
}
void add(int a, int b) {
    db+=b;
    while (a<c) {
        t[a]+=b, a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=t[a];
        a-=lsb(a);
    }
    return ans;
}
void pb(int a, int b, int c, int d) {
    sz.push_back({{a, b}, {c, d}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int kezd, veg; cin >> kezd >> veg;
        pb(kezd, -1, kezd, 0), pb(veg, 1, kezd, 0);
    }
    for (int i=1; i<=m; i++) {
        int x, y, el=0;
        cin >> x;
        for (int j=1; j<=x; j++) {
            cin >> y;
            pb(y, 0, el, i);
            el=y;
        }
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        int id=sz[i].first.second, ert=sz[i].second.first, ki=sz[i].second.second;
        if (id) {
            add(ert, -id);
        } else {
            sol[ki]+=db-ask(ert);
        }
    }
    for (int i=1; i<=m; i++) {
        cout << sol[i] << "\n";
    }
    return 0;
}