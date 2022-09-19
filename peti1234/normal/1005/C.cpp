#include <bits/stdc++.h>

using namespace std;
map<int, int> m;
int n, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto x:m) {
        int ert=x.first, db=x.second;
        bool jo=0;
        for (int p=0; p<=30; p++) {
            int s=(1<<p)-ert;
            if (s==ert) {
                if (db>1) jo=1;
            } else {
                if (m.find(s)!=m.end()) {
                    jo=1;
                }
            }
        }
        if (!jo) {
            ans+=db;
        }
    }
    cout << ans << "\n";
    return 0;
}