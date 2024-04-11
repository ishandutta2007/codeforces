#include <bits/stdc++.h>

using namespace std;
long long n, w, t[505][505];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        long long sum=0;
        for (int i=1; i<=2*n; i++) {
            for (int j=1; j<=2*n; j++) {
                cin >> t[i][j];
                if ((i<=n) == (j<=n)) {
                    sum+=t[i][j];
                }
            }
        }
        cout << sum+min({t[n+1][1], t[n+1][n], t[2*n][1], t[2*n][n], t[1][n+1], t[1][2*n], t[n][n+1], t[n][2*n]}) << "\n";
    }
    return 0;
}