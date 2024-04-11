#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, k, t[c], pref[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        long long maxi=0;
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            pref[i]=pref[i-1]+t[i];
        }
        if (k>=n) {
            cout << pref[n]+n*k-n*(n+1)/2 << "\n";
            continue;
        }
        for (int i=k; i<=n; i++) {
            maxi=max(maxi, pref[i]-pref[i-k]);
        }
        cout << maxi+k*(k-1)/2 << "\n";
    }
    return 0;
}