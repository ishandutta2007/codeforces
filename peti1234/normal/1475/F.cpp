#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int w, n;
bool a[c][c], b[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char c; cin >> c;
                a[i][j]=(c=='1');
            }
        }
        bool baj=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char c; cin >> c;
                b[i][j]=(c=='1');
                if ((a[1][1]+a[1][j]+a[i][1]+a[i][j]+b[1][1]+b[1][j]+b[i][1]+b[i][j])%2) {
                    baj=1;
                }
            }
        }
        cout << (baj? "NO" : "YES") << "\n";
    }
    return 0;
}