#include <bits/stdc++.h>

using namespace std;
int n, k, l;
int t[200002];
long long e, v, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        if (t[i]!=t[i-1]) l=i-1;
        if (i-l>=k) {
            cout << 0 << "\n";
            return 0;
        }
    }
    for (int i=1; i<k; i++) e+=t[k]-t[i];
    for (int i=k+1; i<=n; i++) if (t[i]==t[k]) e--;
    for (int i=n; i>n-k+1; i--) v+=t[i]-t[n-k+1];
    for (int i=n-k; i>=1; i--) if (t[i]==t[n-k+1]) v--;
    for (int i=1; i<=n; i++) m+=abs(t[i]-t[(n+1)/2]);
    m-=n-k;
    cout << min({e, v, m}) << "\n";
    return 0;
}
// Knny volt az F feladatokhoz kpest.