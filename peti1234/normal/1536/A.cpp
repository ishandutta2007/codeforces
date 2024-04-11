#include <bits/stdc++.h>

using namespace std;
int w, n, t[102], maxi, mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        mini=0, maxi=0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            mini=min(mini, t[i]), maxi=max(maxi, t[i]);
        }
        if (mini<0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << maxi-mini+1 << "\n";
            for (int i=mini; i<=maxi; i++) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}