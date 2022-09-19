#include <bits/stdc++.h>

using namespace std;
const int c=205;
int n, m, t[c][c], s[c], o[c];
void svalt(int i) {
    s[i]=1-s[i];
    for (int j=1; j<=m; j++) {
        t[i][j]=1-t[i][j];
    }
}
void ovalt(int j) {
    o[j]=1-o[j];
    for (int i=1; i<=n; i++) {
        t[i][j]=1-t[i][j];
    }
}
void ch() {
    int ut=t[1][m];
    for (int i=2; i<=n; i++) {
        if (t[i][1]!=ut) {
            svalt(i);
        }
        ut=t[i][m];
    }
    ut=0;
    bool baj=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (ut>t[i][j]) {
                baj=1;
            }
            ut=t[i][j];
        }
    }
    if (!baj) {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            cout << s[i];
        }
        cout << "\n";
        for (int j=1; j<=m; j++) {
            cout << o[j];
        }
        cout << "\n";
        exit(0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    for (int j=1; j<=m; j++) {
        if (!t[1][j]) {
            ovalt(j);
        }
    }
    ch();
    for (int j=1; j<=m; j++) {
        ovalt(j);
        ch();
    }
    cout << "NO\n";
    return 0;
}