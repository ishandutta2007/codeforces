#include <bits/stdc++.h>

using namespace std;
const int c=1005;
long long pref[c][c];
void solve() {
    memset(pref, 0, sizeof(pref));
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        int a, b, ter;
        cin >> a >> b;
        ter=a*b;
        pref[a][b]+=ter;
    }
    for (int i=1; i<c; i++) {
        for (int j=1; j<c; j++) {
            pref[i][j]=pref[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c--, d--;
        cout << pref[c][d]-pref[c][b]-pref[a][d]+pref[a][b] << "\n";
    }
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