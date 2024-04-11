#include <bits/stdc++.h>

using namespace std;
int w, n, maxi, mini, p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, maxi=0, mini=1e9, p=1;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            mini=min(mini, x);
            if (x>maxi || (x==maxi && maxi==mini)) maxi=x, p=i;
        }
        if (maxi==mini) cout << -1 << "\n";
        else cout << p << "\n";
    }
    return 0;
}