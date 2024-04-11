#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n, m, r, c;
    cin >> w;
    while (w--) {
        cin >> n >> m >> r >> c;
        int ans=3;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char x;
                cin >> x;
                if (x=='B') {
                    ans=min(ans, 2-(i==r)-(j==c));
                }
            }
        }
        if (ans==3) ans=-1;
        cout << ans << "\n";
    }
    return 0;
}