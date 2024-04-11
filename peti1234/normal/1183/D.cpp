#include <bits/stdc++.h>

using namespace std;
int w, n, db[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        vector<int> sz;
        for (int i=1; i<=n; i++) {
            if (db[i]) sz.push_back(db[i]);
        }
        sort(sz.rbegin(), sz.rend());
        int ans=0, el=n+1;
        for (int i=0; i<sz.size(); i++) {
            int ert=min(sz[i], el-1);
            if (ert) {
                ans+=ert;
                el=ert;
            }
        }

        cout << ans << "\n";

        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
    }
    return 0;
}