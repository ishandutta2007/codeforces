#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long n, m, ans=0;
    cin >> n >> m;
    for (int i=1; i<m; i++) {
        ans+=i;
    }
    for (int i=1; i<=n; i++) {
        ans+=i*m;
    }
    //cout << "valasz...... ";
    cout << ans << "\n";
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}