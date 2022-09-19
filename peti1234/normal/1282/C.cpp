#include <bits/stdc++.h>

using namespace std;
int q;
bool v[200001];
vector<pair<int, int> > sz;
int n, m, a, b, maxi, ido, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> m >> a >> b;
        for (int i=1; i<=n; i++) cin >> v[i];
        sz.clear(), maxi=0, ido=0, db=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            int y;
            if (v[i]) y=b;
            else y=a, db++;
            sz.push_back({x, y});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<sz.size(); i++) {
            int fi=sz[i].first, se=sz[i].second;
            if (sz[i].first>ido) {
                int pl=min(db, (fi-ido-1)/a);
                maxi=max(maxi, i+pl);
            }
            ido+=se;
            if (ido>m) break;
            if (se==a) db--;
        }
        if (ido<=m) maxi=n;
        cout <<  maxi << "\n";
    }
    return 0;
}