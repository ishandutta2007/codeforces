#include <bits/stdc++.h>

using namespace std;
int w, n, m, sum, o, e;
bool v[32][32];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, sum=0;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> v[i][j];
        for (int i=2; i<=(n+m+1)/2; i++) {
            o=0, e=0;
            for (int j=1; j<=n; j++) {
                if (i-j>=1 && i-j<=m) {
                    if (v[j][i-j]) o++;
                    else e++;
                }
                int x=n+m+2-i-j;
                if (x>=1 && x<=m) {
                    if (v[j][x]) o++;
                    else e++;
                }
            }
            sum+=min(o, e);
        }
        cout << sum << "\n";
    }
    return 0;
}