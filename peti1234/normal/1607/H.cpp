#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, a[c], b[c], t[c], ans;
map<int, vector<pair<int, int> > > m;
map<int, set<int> > s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i] >> b[i] >> t[i];
            int ert=a[i]+b[i]-t[i], kis=max(0, a[i]-t[i]), nagy=a[i]-max(0, t[i]-b[i]);
            m[ert].push_back({nagy, kis});
        }
        for (auto p:m) {
            sort(p.second.begin(), p.second.end());
            int ut=-1;
            for (auto x:p.second) {
                if (x.second>ut) {
                    ut=x.first;
                    s[p.first].insert(ut);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
        for (int i=1; i<=n; i++) {
            int ert=a[i]+b[i]-t[i], kis=max(0, a[i]-t[i]);
            auto cel=s[ert].lower_bound(kis);
            cout << a[i]-*cel << " " << t[i]-a[i]+*cel << "\n";
        }

        ans=0, m.clear(), s.clear();
    }
    return 0;
}