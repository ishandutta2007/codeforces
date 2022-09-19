#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, k, pref[c], mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        mini=k;
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            pref[i]=pref[i-1];
            if (c=='W') pref[i]++;
            if (i>=k) {
                mini=min(mini, pref[i]-pref[i-k]);
            }
        }
        cout << mini << "\n";
    }
    return 0;
}