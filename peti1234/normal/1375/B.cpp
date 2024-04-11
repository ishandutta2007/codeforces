#include <bits/stdc++.h>

using namespace std;
int w, n, m, t[302][302];
bool f;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> m, f=0;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            int x; cin >> x;
            bool a=1, b=1;
            if (i==1 || i==n) a=0;
            if (j==1 || j==m) b=0;
            if (x>2+a+b) f=1;
            t[i][j]=2+a+b;
        }
        if (f) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    cout << t[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}