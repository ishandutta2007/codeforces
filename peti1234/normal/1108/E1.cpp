#include <bits/stdc++.h>

using namespace std;
int n, m, t[100005], l[305], r[305], ans;
vector<pair<int, int> > sz;
set<int> s, opt;
void ch() {
    int mini=t[1], maxi=t[1];
    for (int i=1; i<=n; i++) {
        mini=min(mini, t[i]);
        maxi=max(maxi, t[i]);
    }
    if (maxi-mini>ans) {
        ans=maxi-mini;
        opt=s;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> t[i];
    ch();
    for (int i=1; i<=m; i++) {
        cin  >> l[i] >> r[i];
        sz.push_back({l[i], -i});
        sz.push_back({r[i], i});
    }
    sort(sz.begin(), sz.end());
    for (auto p:sz) {
        int k=p.second, id=abs(k);
        if (k<0) s.insert(id);
        else s.erase(id);
        for (int i=l[id]; i<=r[id]; i++) {
            if (k<0) t[i]--;
            else t[i]++;
        }
        ch();
    }
    cout << ans << "\n";
    cout << opt.size() << "\n";
    for (auto x:opt) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}