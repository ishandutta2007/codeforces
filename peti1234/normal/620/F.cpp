#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, m, ut, pref[c], t[c], maxi[c], ans[c];
vector<pair<pair<int, int>, int> > sz;

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        pref[i]=pref[i-1]^i;
    }
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        sz.push_back({{r, l}, i});
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        int l=x.first.second, r=x.first.first, id=x.second;
        while (ut<r) {
            ut++;
            for (int i=1; i<=ut; i++) {
                maxi[i]=max(maxi[i], pref[t[i]]^pref[t[ut]]^min(t[i], t[ut]));
            }
        }
        for (int i=l; i<=r; i++) {
            ans[id]=max(ans[id], maxi[i]);
        }
    }
    for (int i=1; i<=m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}