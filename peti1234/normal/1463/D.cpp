#include <bits/stdc++.h>

using namespace std;
int w, n, mini, maxi, ert, pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, mini=0, maxi=0, ert=0, pos=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            ert-=x-pos-1;
            mini=min(mini, ert);
            ert++;
            maxi=max(maxi, ert);
            pos=x;
        }
        cout << n-maxi+mini+1 << "\n";
    }
    return 0;
}