#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, s[c], ans[c];
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        sz.push_back({s[i], i});
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<n; i++) {
        ans[sz[i].second]=(sz[i].first>sz[i-1].first ? i : ans[sz[i-1].second]);
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if (s[a]>s[b]) ans[a]--;
        if (s[b]>s[a]) ans[b]--;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}