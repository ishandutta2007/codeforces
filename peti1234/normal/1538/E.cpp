#include <bits/stdc++.h>

using namespace std;
int w, n;
map<string, pair<long long, pair<string, string> > > m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            string ki, t;
            cin >> ki >> t;
            if (t[0]==':') {
                string s;
                cin >> s;
                int si=s.size(), h=min(3, si), db=0;
                for (int i=0; i<=si-4; i++) {
                    if (s.substr(i, 4)=="haha") {
                        db++;
                    }
                }
                m[ki]={db, {s.substr(0, h), s.substr(si-h, h)}};
            } else {
                string x, y, f;
                cin >> x >> f >> y;
                auto bal=m[x], jobb=m[y];
                long long ert=bal.first+jobb.first;
                string kezd=bal.second.first+jobb.second.first, veg=bal.second.second+jobb.second.second, kozep=bal.second.second+jobb.second.first;
                while (kezd.size()>3) {
                    kezd.pop_back();
                }
                reverse(veg.begin(), veg.end());
                while (veg.size()>3) {
                    veg.pop_back();
                }
                reverse(veg.begin(), veg.end());
                int si=kozep.size();
                for (int i=0; i<=si-4; i++) {
                    if (kozep.substr(i, 4)=="haha") {
                        ert++;
                    }
                }
                m[ki]={ert, {kezd, veg}};
            }
            if (i==n) {
                cout << m[ki].first << "\n";
            }
        }
        m.clear();
    }
    return 0;
}