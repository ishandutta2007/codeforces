#include <bits/stdc++.h>

using namespace std;
int w, n, maxi, t[50005][6];
int jo(int a, int b) {
    int db=0;
    for (int i=1; i<=5; i++) {
        if (t[a][i]>t[b][i]) {
            db++;
        }
    }
    return (db<3 ? a : b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        maxi=1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=5; j++) {
                cin >> t[i][j];
            }
            maxi=jo(maxi, i);
        }
        for (int i=1; i<=n; i++) {
            if (jo(maxi, i)!=maxi) {
                maxi=0;
            }
        }
        cout << (maxi ? maxi : -1) << "\n";
    }
    return 0;
}