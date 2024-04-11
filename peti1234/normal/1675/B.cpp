#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, t[33], ans=0, baj=0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=n; i>=1; i--) {
            while (i<n && t[i] && t[i]>=t[i+1]) {
                t[i]/=2;
                ans++;
            }
            if (i>1 && t[i]==0) {
                baj=1;
                break;
            }
        }
        cout << (baj ? -1 : ans) << "\n";
    }
    return 0;
}