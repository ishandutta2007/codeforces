#include <bits/stdc++.h>

using namespace std;
int w, n, m, jo;
bool a[1002], b[1002];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m, jo=0;
        for (int i=1; i<=1000; i++) a[i]=0, b[i]=0;
        for (int i=1; i<=n; i++) {int x; cin >> x; a[x]=1;}
        for (int i=1; i<=m; i++) {int x; cin >> x; b[x]=1;}
        for (int i=1; i<=1000; i++) if (a[i] && b[i] && !jo) jo=1, cout << "YES\n" << 1 << " " << i << "\n";
        if (!jo) cout << "NO\n";
    }
    return 0;
}