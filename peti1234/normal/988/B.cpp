#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, string> > sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        sz.push_back({s.size(), s});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int si=sz[i].first, sj=sz[j].first;
            bool jo=0;
            for (int pos=0; pos<=sj-si; pos++) {
                if (sz[j].second.substr(pos, si)==sz[i].second) {
                    jo=1;
                }
            }
            if (!jo) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (auto x:sz) {
        cout << x.second << "\n";
    }
    return 0;
}