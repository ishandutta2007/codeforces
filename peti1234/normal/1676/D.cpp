#include <bits/stdc++.h>

using namespace std;
const int c=205;
long long w, n, m, t[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cin >> t[i][j];
            }
        }
        long long maxi=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                long long sum=-t[i][j];
                for (int a=1; a<=n; a++) {
                    int b=i+j-a;
                    if (1<=b && b<=m) sum+=t[a][b];
                    b=j+a-i;
                    if (1<=b && b<=m) sum+=t[a][b];
                }
                maxi=max(maxi, sum);
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}