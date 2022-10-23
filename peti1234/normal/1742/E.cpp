#include <bits/stdc++.h>

using namespace std;
long long maxi[200005], pref[200005], t[200005], n, q;
void solve() {
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=pref[i-1]+t[i];
        maxi[i]=max(maxi[i-1], t[i]);
    }
    while (q--) {
        int ert;
        cin >> ert;
        int lo=0, hi=n+1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (maxi[mid]<=ert) lo=mid;
            else hi=mid;
        }
        cout << pref[lo] << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}