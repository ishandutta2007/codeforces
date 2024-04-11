#include <bits/stdc++.h>

using namespace std;
long long n, k, ert, add, ans, t[200005], pref[200005];
void solve() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=pref[i-1]+t[i];
    }
    ert=pref[n]-n*k, ans=ert;
    for (long long i=n; i>=1; i--) {
        ert-=t[i], ert+=k, add=0;
        long long f=2;
        for (long long j=i; j<=min(n, i+30); j++) {
            add+=t[j]/f;
            f*=2;
        }
        ans=max(ans, ert+add);
    }




    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
4 5
10 10 3 1
*/