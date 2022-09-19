#include <bits/stdc++.h>

using namespace std;
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, m, jo=1;
        vector<pair<pair<int, int>, pair<int, int> > > ans;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                if (c=='1') {
                    if (i==1 && j==1) {
                        jo=0;
                    }
                    ans.push_back({{(i==1 ? i : i-1), (i==1 ? j-1 : j)}, {i, j}});
                }
            }
        }
        if (!jo) {
            cout << -1 << "\n";
        } else {
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (auto x:ans) {
                cout << x.first.first << " " << x.first.second << " " << x.second.first << " " << x.second.second << "\n";
            }
        }
        ans.clear();
    }
    return 0;
}