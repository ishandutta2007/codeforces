#include <bits/stdc++.h>

using namespace std;
int w, n, h, maxi, mini, el;
bool baj;
vector<pair<int, pair<int, int> > > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> h;
        mini=h, maxi=h, el=0, baj=0;
        sz.clear();
        for (int i=0; i<n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            sz.push_back({a, {b, c}});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<n; i++) {
            int ert=sz[i].first, kis=sz[i].second.first, nagy=sz[i].second.second, tav=ert-el;
            mini=max(mini-tav, kis), maxi=min(maxi+tav, nagy);
            if (mini>maxi) {
                baj=1;
            }
            el=ert;
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}