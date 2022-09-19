#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, m, t[c], db[c], sum, o;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        s.insert(i);
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        int ert=t[i]%m;
        auto it=s.lower_bound(ert);
        if (it==s.end()) {
            it=s.begin();
        }
        int val=*it;
        db[val]++;
        if (db[val]==n/m) {
            s.erase(val);
        }
        int lep=(val-ert+m)%m;
        sum+=lep, t[i]+=lep;
    }
    cout << sum << "\n";
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    return 0;
}