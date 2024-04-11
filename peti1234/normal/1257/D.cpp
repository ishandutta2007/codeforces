#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > r, sz;
int t[200001], n, m;
int ker(int a)
{
    int si=sz.size();
    int x=-1, y=si-1;
    while(y-x>1) {
        int z=(x+y)/2;
        if (sz[z].first>=a) {
            y=z;
        } else {
            x=z;
        }
    }
    return sz[y].second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> n;
        int p=0, q=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            p=max(p, t[i]);
        }
        r.clear();
        sz.clear();
        cin >> m;
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            q=max(q, a);
            r.push_back({a, b});
        }
        if (p>q) {
            cout << -1 << "\n";
            continue;
        }
        sort(r.begin(), r.end());
        for (int i=0; i<r.size(); i++) {
            int x=r[i].second;
            while(sz.size()>0 && x>=sz.back().second) {
                sz.pop_back();
            }
            sz.push_back(r[i]);
        }
        int maxi=0, db=0;
        int ans=1;
        for (int i=1; i<=n+1; i++) {
            if (i==n+1) {
                break;
            }
            maxi=max(maxi, t[i]);
            db++;
            if (ker(maxi)<db) {
                ans++;
                maxi=t[i], db=1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}