#include <bits/stdc++.h>

using namespace std;
int n, m, us, uo, w;
bool v[52][52];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, us=0, uo=0;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> v[i][j];
        for (int i=1; i<=n; i++) {
            bool p=1;
            for (int j=1; j<=m; j++) if (v[i][j]) p=0;
            us+=p;
        }
        for (int j=1; j<=m; j++) {
            bool p=1;
            for (int i=1; i<=n; i++) if (v[i][j]) p=0;
            uo+=p;
        }
        us=min(us, uo);
        if (us%2) cout << "Ashish" << "\n";
        else cout << "Vivek" << "\n";
    }
    return 0;
}