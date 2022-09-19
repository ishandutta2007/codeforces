#include <bits/stdc++.h>

using namespace std;
const int c=202;
int w, n, m, xo[c], jo;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m, jo=0;
        for (int i=1; i<=n+m; i++) xo[i]=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int x; cin >> x;
                xo[i+j]^=x;
            }
        }
        for (int i=1; i<=n+m; i++) {
            if (xo[i]) jo=1;
        }
        if (jo) cout << "Ashish\n";
        else cout << "Jeel\n";
    }
    return 0;
}