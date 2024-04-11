#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, m, a[c], b[c], s[c], spec, cnt, ut;
vector<int> sz[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        spec=cnt=0;
        ans.clear();
        for (int i=1; i<=n; i++) {
            sz[i].clear();
        }
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            if (a[i]!=b[i]) {
                cnt++;
                sz[b[i]].push_back(i);
            }
        }
        for (int i=1; i<=m; i++) {
            cin >> s[i];
        }
        ut=s[m];
        for (int i=1; i<=n; i++) {
            if (b[i]==ut) {
                spec=i;
            }
        }
        if (sz[ut].size()) {
            spec=sz[ut].back();
            sz[ut].pop_back();
            cnt--;
        }
        for (int i=1; i<m; i++) {
            if (sz[s[i]].size()) {
                ans.push_back(sz[s[i]].back());
                sz[s[i]].pop_back();
                cnt--;
            } else {
                ans.push_back(spec);
            }
        }
        ans.push_back(spec);
        if (cnt || !spec) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i:ans) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}