#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, m, q, rossz[c], pref[c];
vector<vector<bool>> sz;
int main()
{
    cin >> n >> m;
    sz.resize(n+1);
    for (int i=1; i<=n; i++) {
        sz[i].resize(m+1);
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            sz[i][j]=(c=='.');
        }
    }
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            if (!sz[i-1][j] && !sz[i][j-1]) {
                rossz[j]=1;
            }
        }
    }
    for (int j=2; j<=m; j++) {
        pref[j]=pref[j-1]+rossz[j];
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        cout << (pref[l]==pref[r] ? "YES" : "NO") << "\n";
    }
    return 0;
}