#include <bits/stdc++.h>

using namespace std;
bool v[102];
int n, k, db, w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, db=0;
        for (int i=1; i<=n; i++) v[i]=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (!v[x]) v[x]=1, db++;
        }
        if (db>k) cout << -1 << "\n";
        else {
            cout << n*k << "\n";
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (v[j]) cout << j << " ";
                }
                for (int j=1; j<=k-db; j++) cout << 1 << " ";
            }
            cout << "\n";
        }

    }
    return 0;
}