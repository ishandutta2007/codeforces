#include <bits/stdc++.h>

using namespace std;
const int c=502;
int n, t[c][c], ans[2*c], cnt, vez;
vector<pair<int, int> > sol;
map<pair<int, int>, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cnt=n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        vector<pair<int, int> > sz;
        for (int j=1; j<=n; j++) {
            sz.push_back({t[i][j], j});
            sort(sz.begin(), sz.end());
        }
        ans[i]=t[i][i];
        int el=i;
        for (int j=1; j<n; j++) {
            if (sz[j].second>i) {
                if (sz[j].first==sz[j-1].first) {
                    continue;
                }
                cnt++;
                sol.push_back({el, cnt});
                m[{sz[j].first, i}]=cnt;
                el=cnt;
                ans[cnt]=sz[j].first;
            } else {
                sol.push_back({el, m[sz[j]]});
                break;
            }
        }
        if (i==1) {
            vez=cnt;
        }
    }
    cout << cnt << "\n";
    for (int i=1; i<=cnt; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    cout << vez << "\n";
    for (auto i:sol) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}