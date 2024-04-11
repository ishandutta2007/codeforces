#include <bits/stdc++.h>

using namespace std;
int n, t[100005];
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    cout << t[n-1]+t[n]-t[1]-t[2] << "\n";


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