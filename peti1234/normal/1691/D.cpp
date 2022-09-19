#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, t[c], pref[c];
bool baj;
void solve() {
    vector<int> pos, ert;
    ert.push_back(0), pos.push_back(0);

    for (int i=1; i<=n; i++) {
        while (pos.back()!=0 && t[i]>=t[pos.back()]) {
            pos.pop_back();
        }
        while (ert.back()!=0 && pref[i-1]<=pref[ert.back()]) {
            ert.pop_back();
        }
        if (pos.back()==0 && pref[i-1]>pref[ert.back()]) {
            baj=1;
        }
        if (pos.back()>0 && ert.back()>=pos.back()) {
            baj=1;
        }
        pos.push_back(i);
        ert.push_back(i-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        baj=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            pref[i]=pref[i-1]+t[i];
        }
        solve();
        reverse(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            pref[i]=pref[i-1]+t[i];
        }
        solve();
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}