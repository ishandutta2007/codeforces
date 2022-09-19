#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, m, t[c], maxi[c], cnt;
map<int, int> id;
set<int> sz[c];
vector<pair<int, int> > val;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (!id[x]) {
                id[x]=++cnt;
            }
            t[i]=id[x];
            sz[t[i]].insert(i);
        }
        for (int i=1; i<=m; i++) {
            int l, r;
            cin >> l >> r;
            maxi[l]=max(maxi[l], r);
        }
        for (int i=1; i<=n; i++) {
            maxi[i]=max({i, maxi[i-1], maxi[i]});
            auto it=sz[t[i]].upper_bound(i);
            if (it!=sz[t[i]].end() && *it<=maxi[i]) {
                //cout << "fontos " << i << " " << (*it) << "\n";
                val.push_back({i, *it});
            }
            it=sz[t[i]].upper_bound(maxi[i]);
            it--;
            if (i<*it) {
                //cout << "spec " << i << " " << (*it) << "\n";
                val.push_back({i, *it});
            }
        }
        int si=val.size(), ans=n, kis=n+1, nagy=0;
        if (!si) {
            ans=0;
        } else {
            ans=val[si-1].first-val[0].first+1;
            for (int i=0; i<si; i++) {
                int fi=val[i].first, se=val[i].second;
                kis=min(kis, se), nagy=max(nagy, se);
                if (i+1<si) {
                    ans=min(ans, max(nagy, val[si-1].first)-min(kis, val[i+1].first)+1);
                }
            }
            ans=min(ans, nagy-kis+1);
        }
        //cout << "valasz............... ";
        cout << ans << "\n";
        for (int i=1; i<=n; i++) {
            t[i]=0, maxi[i]=0;
            sz[i].clear();
        }
        id.clear(), val.clear();
        cnt=0;
    }
    return 0;
}
/*
1
7 3
1 1 2 1 3 3 5
1 4
4 5
2 4
*/