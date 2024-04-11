#include <bits/stdc++.h>

using namespace std;
int n, t[52], jo, w;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, jo=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=2; i<=n; i++) if (t[i]-t[i-1]>1) jo++;
        if (jo) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}