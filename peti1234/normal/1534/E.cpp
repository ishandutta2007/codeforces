#include <bits/stdc++.h>

using namespace std;
const int c=502;
int n, k, n2, db[c], maxi=1;
long long xo, ert;
int main()
{
    cin >> n >> k;
    if (n%2 && k%2==0) {
        cout << -1 << "\n";
        return 0;
    }
    n2=n;
    for (int i=1; i<=n; i++) {
        db[i]=1;
    }
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=n; i++) {
            if (n2%k || n2/k<maxi) {
                db[i]+=2;
                maxi=max(maxi, db[i]);
                n2+=2;
            }
        }
    }
    for (int i=1; i<=n2/k; i++) {
        vector<pair<int, int> > sz;
        for (int j=1; j<=n; j++) {
            sz.push_back({db[j], j});
        }
        sort(sz.rbegin(), sz.rend());
        cout << "? ";
        for (int j=0; j<k; j++) {
            cout << sz[j].second << " ";
            db[sz[j].second]--;
        }
        cout.flush() << endl;
        cin >> ert;
        xo^=ert;
    }
    cout << "! " << xo << "\n";
    return 0;
}