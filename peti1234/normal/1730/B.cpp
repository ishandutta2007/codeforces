#include <bits/stdc++.h>

using namespace std;
int n, pos[100005], t[100005];
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> pos[i];
    int maxi=pos[1], mini=pos[1];
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        mini=min(mini, pos[i]-t[i]);
        maxi=max(maxi, pos[i]+t[i]);
    }
    long long dif=maxi+mini;
    cout << dif/2;
    if (dif%2) {
        cout << ".5";
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