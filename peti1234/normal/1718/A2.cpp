#include <bits/stdc++.h>

using namespace std;
int n;
map<int, int> m;
void solve() {
    cin >> n;
    int ans=n, xo=0, ut=-1;
    m[0]=0;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        xo^=x;
        if (m.find(xo)!=m.end() && m[xo]>=ut) {
            ans--;
            ut=i;
        }
        m[xo]=i;
    }
    //cout << "valasz................. ";
    cout << ans << "\n";
    m.clear();
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