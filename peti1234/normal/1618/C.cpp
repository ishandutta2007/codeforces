#include <bits/stdc++.h>

using namespace std;
long long w, n, t[105], g[2];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            g[i%2]=__gcd(g[i%2], t[i]);
        }
        bool jo0=1, jo1=1;
        for (int i=1; i<=n; i+=2) {
            if (t[i]%g[0]==0) jo0=0;
        }
        for (int i=2; i<=n; i+=2) {
            if (t[i]%g[1]==0) jo1=0;
        }
        if (jo0) cout << g[0] << "\n";
        else if (jo1) cout << g[1] << "\n";
        else cout << 0 << "\n";
        g[0]=0, g[1]=0;
    }
    return 0;
}