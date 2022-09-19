#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, m, kezd[c], veg[c], t[c], ans[c];
bool jo=1;
priority_queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> kezd[i] >> veg[i] >> t[i];
        if (ans[veg[i]]) jo=0;
        ans[veg[i]]=m+1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (kezd[j]==i) {
                for (int k=1; k<=t[j]; k++) {
                    q.push({-veg[j], j});
                }
            }
        }
        if (ans[i]) continue;
        if (q.size()>0) {
            if (i>-q.top().first) {
                jo=0;
            }
            ans[i]=q.top().second;
            q.pop();
        }
    }
    if (q.size()>0 || !jo) {
        cout << -1 << "\n";
    } else {
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}