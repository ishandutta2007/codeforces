#include <bits/stdc++.h>

using namespace std;
int w, t[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, m; cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int x; cin >> x;
                if ((i+j+x)%2) x++;
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}