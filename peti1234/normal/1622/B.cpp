#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005], ans[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        string s;
        cin >> s;
        vector<pair<pair<int, int>, int> > sz;
        for (int i=1; i<=n; i++) {
            sz.push_back({{s[i-1]-'0', t[i]}, i});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<n; i++) {
            ans[sz[i].second]=i+1;
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}