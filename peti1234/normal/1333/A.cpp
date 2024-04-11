#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (n%2==0 && m%2==0 && i==n && j==m-1) cout << 'B';
                else if (n%2!=m%2 && i==n && j==m) cout << 'B';
                else if (i%2==j%2) cout << 'B';
                else cout << 'W';
            }
            cout << "\n";
        }
    }
    return 0;
}
// Nem a legegyszerb megoldst talltam meg, rdemse szls helyzetbl nzni, hogy mi trtnik.