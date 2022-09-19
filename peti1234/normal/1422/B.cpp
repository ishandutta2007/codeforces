#include <bits/stdc++.h>

using namespace std;
int w, n, m, t[102][102], p[4];
long long sum=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, sum=0;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> t[i][j];
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            p[0]=t[i][j], p[1]=t[n+1-i][j], p[2]=t[i][m+1-j], p[3]=t[n+1-i][m+1-j];
            sort(p, p+4);
            sum+=p[2]+p[3]-p[0]-p[1];
        }
        cout << sum/4 << "\n";
    }
    return 0;
}