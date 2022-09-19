#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c], ert[c], sum=0, ans=1, mod=998244353;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (s.find(t[i])==s.end()) {
            ert[i]++;
            s.insert(t[i]);
        }
    }
    for (int i=n; i>=1; i--) {
        if (s.find(t[i])!=s.end()) {
            ert[i]--;
            s.erase(t[i]);
        }
    }
    for (int i=1; i<n; i++) {
        sum+=ert[i];
        if (!sum) {
            ans=2*ans%mod;
        }
    }
    cout << ans << "\n";
    return 0;
}