#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], db[c], maxi, r[c];
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            r[i]=t[i];
            db[t[i]]++;
        }
        for (int i=1; i<=n; i++) {
            maxi=max(maxi, db[i]);
        }
        sort(r+1, r+n+1);
        for (int i=1; i<=n; i++) {
            int kov=i+maxi;
            if (kov>n) kov-=n;
            sz[r[i]].push_back(r[kov]);
        }
        for (int i=1; i<=n; i++) {
            cout << sz[t[i]].back() << " ";
            sz[t[i]].pop_back();
        }
        cout << "\n";
        for (int i=1; i<=n; i++) {
            t[i]=0, db[i]=0, r[i]=0;
            sz[i].clear();
        }
        maxi=0;
    }
    return 0;
}