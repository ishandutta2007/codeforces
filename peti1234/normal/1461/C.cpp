#include <bits/stdc++.h>

using namespace std;
int w, n, m, ut, x;
long double ans, p;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m, ans=1, ut=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (x!=i) ut=i;
        }
        if (!ut) ans=0;
        for (int i=1; i<=m; i++) {
            cin >> x >> p;
            if (x>=ut) {
                ans*=(1.0-p);
            }
        }
        cout.precision(10);
        cout << 1.0-ans << "\n";
    }
    return 0;
}