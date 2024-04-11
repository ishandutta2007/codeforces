#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, a[c], b[c], cnt;
vector<pair<int, int> > sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    for (int i=n; i>=1; i--) {
        int x=a[i], y=b[i];
        if (x!=i || y!=i) {
            sol.push_back({i, y});
            sol.push_back({x, i});
            for (int j=1; j<=n; j++) {
                if (a[j]==i) {
                    swap(a[j], a[i]);
                }
                if (b[j]==i) {
                    swap(b[j], b[i]);
                }
            }
        }
    }
    cnt=sol.size();
    cout << cnt/2 << "\n";
    for (int i=0; i<cnt; i++) {
        cout << sol[i].first << " " << sol[i].second << " ";
        if (i%2) {
            cout << "\n";
        }
    }
    return 0;
}