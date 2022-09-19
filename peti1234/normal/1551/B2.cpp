#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, k, t[c], db[c], ans[c];
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            db[t[i]]++;
            if (db[t[i]]<=k) {
                sz.push_back({t[i], i});
            }
        }
        sort(sz.begin(), sz.end());
        int si=sz.size();
        si=si/k*k;
        for (int i=0; i<si; i++) {
            ans[sz[i].second]=(i%k)+1;
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<=n; i++) {
            db[i]=0, ans[i]=0;
        }
        sz.clear();
    }
    return 0;
}