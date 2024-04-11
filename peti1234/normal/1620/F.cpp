#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, t[c];
vector<pair<pair<int, int>, pair<int, int> > > sz[c];
void pb(int a, int b, int c, int d, int e) {
    sz[a].push_back({{b, c}, {d, e}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        pb(0, -c, -c, 0, 0);
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            for (auto p:sz[i-1]) {
                int x=p.first.first, y=p.first.second;
                if (t[i]>x) {
                    pb(n+1, t[i], y, x, y);
                } else if (t[i]>y) {
                    pb(n+1, x, t[i], x, y);
                }
                if (-t[i]>x) {
                    pb(n+1, -t[i], y, x, y);
                } else if (-t[i]>y) {
                    pb(n+1, x, -t[i], x, y);
                }
            }
            sort(sz[n+1].begin(), sz[n+1].end());
            for (auto x:sz[n+1]) {
                if (sz[i].size()==0 || x.first.second<sz[i].back().first.second) {
                    sz[i].push_back(x);
                }
            }
            sz[n+1].clear();
        }
        if (sz[n].size()>0) {
            cout << "YES\n";
            vector<int> res;
            pair<int, int> p=sz[n][0].first;
            for (int i=n; i>=1; i--) {
                for (auto j:sz[i]) {
                    if (j.first==p) {
                        res.push_back(abs(p.first)==t[i] ? p.first : p.second);
                        p=j.second;
                        break;
                    }
                }
            }
            reverse(res.begin(), res.end());
            for (auto x:res) {
                cout << x << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
        for (int i=0; i<=n; i++) {
            sz[i].clear();
        }
    }
    return 0;
}