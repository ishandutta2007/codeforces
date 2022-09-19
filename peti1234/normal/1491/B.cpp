#include <bits/stdc++.h>

using namespace std;
int w, n, u, v, t[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> u >> v;
        int maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=2; i<=n; i++) {
            maxi=max(maxi, abs(t[i]-t[i-1]));
        }
        if (maxi>1) {
            cout << 0 << "\n";
        }
        if (maxi==1) {
            cout << min(u, v) << "\n";
        }
        if (maxi==0) {
            cout << v+min(u, v) << "\n";
        }
    }
    return 0;
}