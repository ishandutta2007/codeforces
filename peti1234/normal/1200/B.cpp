#include <bits/stdc++.h>

using namespace std;
int w, n, db, dif, t[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> db >> dif;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        bool baj=0;
        for (int i=1; i<n; i++) {
            db+=t[i];
            db-=max(0, t[i+1]-dif);
            if (db<0) baj=1;
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}