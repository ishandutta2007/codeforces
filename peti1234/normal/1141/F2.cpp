#include <bits/stdc++.h>

using namespace std;
int n, t[1505], pref[1505];
vector<pair<int, int> > ans, ert;
map<int, vector<pair<int, int> > > m;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=pref[i-1]+t[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            m[pref[j]-pref[i-1]].push_back({i, j});
        }
    }
    for (auto f:m) {
        auto sz=f.second;
        sort(sz.begin(), sz.end());
        ert.clear();
        for (auto x:sz) {
            if (ert.size()>0 && x.second<ert.back().second) {
                ert.pop_back();
            }
            if (ert.size()==0 || x.first>ert.back().second) {
                ert.push_back(x);
            }
        }
        if (ert.size()>ans.size()) {
            ans=ert;
        }
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}