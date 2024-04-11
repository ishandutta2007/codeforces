#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, k;
        cin >> n >> k;
        int mini, maxi;
        cin >> mini;
        maxi=mini;
        for (int i=1; i<n; i++) {
            int x;
            cin >> x;
            mini=min(mini, x);
            maxi=max(maxi, x);
        }

        if (maxi-mini>2*k) {
            cout << -1 << "\n";
        } else {
            cout << mini+k << "\n";
        }
    }
    return 0;
}