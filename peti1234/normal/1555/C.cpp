#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, pref[c], suf[c], mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> suf[i];
        }
        for (int i=n-1; i>=1; i--) {
            suf[i]+=suf[i+1];
        }
        for (int i=1; i<=n; i++) {
            cin >> pref[i];
            pref[i]+=pref[i-1];
        }
        if (n==1) {
            cout << 0 << "\n";
            continue;
        }
        mini=min(pref[n-1], suf[2]);
        for (int i=2; i<n; i++) {
            mini=min(mini, max(pref[i-1], suf[i+1]));
        }
        cout << mini << "\n";
    }
    return 0;
}