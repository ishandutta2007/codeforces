#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, m, pos=0;
    vector<pair<int, int> > ans;
    string s, t[15];
    cin >> s >> m;
    for (int i=1; i<=m; i++) cin >> t[i];
    n=s.size();
    while (pos<n) {
        int maxi=pos-1, kezd=0, id=0;
        for (int i=1; i<=m; i++) {
            for (int j=0; j<=pos; j++) {
                int si=t[i].size();
                if (maxi<si+j && si+j<=n && s.substr(j, si)==t[i]) {
                    maxi=si+j-1;
                    kezd=j, id=i;
                }
            }
        }
        if (maxi==pos-1) break;
        ans.push_back({id, kezd+1});
        pos=maxi+1;
    }
    if (pos<n) cout << -1 << "\n";
    else {
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}