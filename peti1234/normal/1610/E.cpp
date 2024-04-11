#include <bits/stdc++.h>

using namespace std;
int w, n, maxi;
map<int, int> m;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            s.insert(x);
            m[x]++;
        }
        for (auto p:s) {
            int cnt=m[p], ert=p;
            auto kov=s.upper_bound(p);
            while (kov!=s.end()) {
                cnt++;
                ert=*kov;
                kov=s.lower_bound(2*ert-p);
            }
            maxi=max(maxi, cnt);
        }
        cout << n-maxi << "\n";
        maxi=0;
        s.clear();
        m.clear();
    }
    return 0;
}