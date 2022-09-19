#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, t[c], pref[c], suf[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        pref[i]=pref[i-1]+(i%2 ? 1 : -1)*t[i];
    }
    for (int i=n; i>=1; i--) {
        suf[i]=suf[i+1]+(i%2 ? 1 : -1)*t[i];
    }
    for (int i=1; i<=n; i++) {
        if (pref[i-1]==suf[i+1]) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}