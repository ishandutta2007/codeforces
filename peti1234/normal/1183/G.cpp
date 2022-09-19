#include <bits/stdc++.h>

using namespace std;
int w, n, db[200005], f[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x, y;
            cin >> x >> y;
            db[x]++;
            f[x]+=y;
        }
        vector<pair<int, int> > sz;
        for (int i=1; i<=n; i++) {
            if (db[i]) sz.push_back({f[i], db[i]});
        }
        sort(sz.rbegin(), sz.rend());
        int ans=0, spec=0;
        set<int> s;
        for (int i=1; i<=n; i++) {
            s.insert(i);
        }
        for (int i=0; i<sz.size(); i++) {
            int a=sz[i].first, b=sz[i].second;
            if (b>=*(s.begin())) {
                auto it=s.upper_bound(b);
                it--;
                int ert=*it;
                ans+=ert, spec+=min(a, ert);
                s.erase(it);
            }
        }

        cout << ans << " " << spec << "\n";

        for (int i=1; i<=n; i++) {
            db[i]=0, f[i]=0;
        }
    }
    return 0;
}