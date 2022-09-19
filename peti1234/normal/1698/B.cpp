#include <bits/stdc++.h>

using namespace std;
int t[200005];
void solve() {
    int n, k, cnt=0;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=2; i<n; i++) {
        if (t[i]>t[i-1]+t[i+1]) cnt++;
    }
    cout << (k==1 ? (n-1)/2 : cnt) << "\n";
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