#include <bits/stdc++.h>

using namespace std;
const int c=105, c2=10005;
int n, k, cnt, t[c2], db[c2], ert, ans1[c], ans2[c], pos[c], maxi;
void solve() {
    for (int i=1; i<=n; i++) {
        pos[i]=0;
    }
    for (int i=maxi+1; ; i++) {
        int s=t[i];
        if (!ans1[s]) {
            if (!pos[s]) {
                pos[s]=i;
            } else {
                ans1[s]=pos[s], ans2[s]=i;
                for (int j=pos[s]; j<=i; j++) {
                    db[j]++;
                    if (db[j]==cnt) {
                        maxi=j;
                    }
                }
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n*k; i++) {
        cin >> t[i];
    }
    cnt=(n+k-2)/(k-1);
    for (int i=1; i<=n; i++) {
        solve();
    }
    for (int i=1; i<=n; i++) {
        cout << ans1[i] << " " << ans2[i] << "\n";
    }
    return 0;
}