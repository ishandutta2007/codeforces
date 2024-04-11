#include <bits/stdc++.h>

using namespace std;
int n, m, jo[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j=l; j<=r; j++) jo[j]=1;
    }
    int db=0;
    for (int i=1; i<=m; i++) if (!jo[i]) db++;
    cout << db << "\n";
    for (int i=1; i<=m; i++) if (!jo[i]) cout << i << " ";
    cout << "\n";
    return 0;
}