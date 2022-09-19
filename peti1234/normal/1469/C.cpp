#include <bits/stdc++.h>

using namespace std;
long long w, n, k, mini, maxi, x;
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, k--, baj=0;
        cin >> mini, maxi=mini;
        for (int i=2; i<=n; i++) {
            cin >> x;
            mini=max(mini-k, x);
            maxi=min(maxi+k, x+k);
            if (i==n) {
                mini=max(mini, x);
                maxi=min(maxi, x);
            }
            if (mini>maxi) {
                baj=1;
            }
        }
        cout << (baj? "NO" : "YES") << "\n";
    }
    return 0;
}