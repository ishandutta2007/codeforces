#include <bits/stdc++.h>

using namespace std;
int n, w, t[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        int mini=1e9, maxi=0, maxdif=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            if (t[i]!=-1) {
                if (i>1 && t[i-1]!=-1) {
                    maxdif=max(maxdif, abs(t[i]-t[i-1]));
                }
                if (i>1 && t[i-1]==-1) {
                    mini=min(mini, t[i]);
                    maxi=max(maxi, t[i]);
                }
                if (i<n && t[i+1]==-1) {
                    mini=min(mini, t[i]);
                    maxi=max(maxi, t[i]);
                }
            }
        }
        mini=min(mini, maxi);
        int dif=(maxi-mini+1)/2, koz=(maxi+mini)/2;
        cout << max(maxdif, dif) << " " << koz << "\n";
    }
    return 0;
}