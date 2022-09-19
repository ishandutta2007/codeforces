#include <bits/stdc++.h>

using namespace std;
int w, n, m, a, b, ido, db, t[200002];
int main()
{
    cin >> w;
    while(w--) {
        cin >> m >> n >> a >> b, db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        if (a<b) {
            ido=b-2;
        } else {
            ido=m-b-1;
        }
        for (int i=n; i>=1; i--) {
            if (t[i]<=ido) {
                db++, ido--;
            }
        }
        cout << min(db, abs(a-b)-1) << "\n";
    }
    return 0;
}