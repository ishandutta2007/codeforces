#include <bits/stdc++.h>

using namespace std;
int w, n, k, t[100005], db;
set<pair<int, int> > s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=2; i<=n; i++) {
            s.insert({t[i], t[i-1]});
        }
        sort(t+1, t+n+1);
        for (int i=2; i<=n; i++) {
            if (s.find({t[i], t[i-1]})==s.end()) {
                db++;
            }
        }
        cout << (db+1<=k ? "YES" : "NO") << "\n";
        s.clear();
        db=0;
    }
    return 0;
}