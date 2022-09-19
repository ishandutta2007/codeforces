#include <bits/stdc++.h>

using namespace std;
int w, n, k;
set<int> s;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            s.insert(x);
            m[x]++;
        }
        int ert=0, db=k;
        while (db || s.find(ert)!=s.end()) {
            if (s.find(ert)==s.end()) db--;
            ert++;
        }
        vector<int> sz;
        for (auto x:m) {
            if (x.first>ert) {
                sz.push_back(x.second);
            }
        }
        sort(sz.begin(), sz.end());
        int ans=0, kk=k;
        for (auto x:sz) {
            if (kk>=x) {
                kk-=x;
            } else {
                ans++;
            }
        }
        cout << ans << "\n";

        s.clear(), m.clear();
    }
    return 0;
}
/*
1
4 1
0 2 4 5
*/