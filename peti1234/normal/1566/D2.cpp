#include <bits/stdc++.h>

using namespace std;
int w, n, m, t[100005], ans;
vector<pair<int, int> > sz;
vector<int> sor[305];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n*m; i++) {
            cin >> t[i];
            sz.push_back({t[i], i});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<n*m; i+=m) {
            for (int j=0; j<m; j++) {
                sor[i/m].push_back(sz[i+j].second);
                //cout << "ertek " << i/m << " " << sz[i+j].second << "\n";
            }
        }
        for (int i=0; i<n; i++) {
            sort(sor[i].begin(), sor[i].end());
            for (int j=0; j<m; j++) {
                for (int k=j+1; k<m; k++) {
                    //cout << "par " << sor[i][j] << " " << sor[i][k] << "\n";
                    if (t[sor[i][j]]<t[sor[i][k]]) {
                        ans++;
                    }
                }
            }
        }
        //cout << "valasz: ";
        cout << ans << "\n";
        sz.clear();
        for (int i=0; i<n; i++) {
            sor[i].clear();
        }
        ans=0;
    }
    return 0;
}
/*
1
1 2
1 2
*/