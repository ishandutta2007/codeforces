#include <bits/stdc++.h>

using namespace std;
int w, t[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, jo=0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        for (int i=2; i<=n; i++) {
            if (t[i]==t[i-1]) jo++;
        }
        if (jo) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}