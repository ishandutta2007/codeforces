#include <bits/stdc++.h>

using namespace std;
long long w, n, x, maxi, p, db, e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> x, maxi=0, e=0;
        for (int i=1; i<=n; i++) {
            cin >> p;
            if (p==x) e=1;
            maxi=max(maxi, p);
        }
        if (e) {
            cout << 1 << "\n";
        } else {
            db=x/maxi;
            if (maxi*db!=x) db++;
            if (db==1) db++;
            cout << db << "\n";
        }
    }
    return 0;
}