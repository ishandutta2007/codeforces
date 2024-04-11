#include <bits/stdc++.h>

using namespace std;
int w, n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (i==1 && j%2 || j==1 && i%2 || i==n && j>2 && (m-j)%2==0 || j==m && i>2 && (n-i)%2==0) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}