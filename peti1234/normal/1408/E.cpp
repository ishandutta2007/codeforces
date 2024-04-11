#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, ki[c];
int holvan(int a) {
    if (!ki[a]) return a;
    int x=ki[a];
    ki[a]=holvan(x);
    return ki[a];
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) ki[a]=b;
    return a==b;
}
long long sum, a[c], b[c], el[c];
vector<pair<long long, pair<int, int> > > sz;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i=1; i<=m; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=m; i++) {
        int x; cin >> x;
        for (int j=1; j<=x; j++) {
            int y; cin >> y;
            sz.push_back({a[i]+b[y], {i, y}});
        }
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<sz.size(); i++) {
        long long ert=sz[i].first;
        int csop=sz[i].second.first, ut=el[csop], id=sz[i].second.second;
        if (ut && unio(ut, id)) sum+=ert;
        else el[csop]=id;
    }
    cout << sum << "\n";
    return 0;
}
// e