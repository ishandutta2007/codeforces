#include <bits/stdc++.h>

using namespace std;
int w, n, x, y, a[100002], c;
bool jo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, x=n+1, y=n+1, jo=true;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            if (a[i]==1) x=min(x, i);
            if (a[i]==-1) y=min(y, i);
        }
        for (int i=1; i<=n; i++) {
            cin >> c;
            if (c>a[i] && i<=x || c<a[i] && i<=y) jo=false;
        }
        if (jo) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
// Knny B feladat.