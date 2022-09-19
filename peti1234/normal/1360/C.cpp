#include <bits/stdc++.h>

using namespace std;
int w;
int n, t[52], db;
bool v=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, v=0, db=0;
        for (int i=1; i<=n; i++) cin >> t[i], db+=(t[i]%2);
        sort(t+1, t+n+1);
        for (int i=2; i<=n; i++) if (t[i]-t[i-1]==1) v=1;
        if (db%2==0 || v) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}