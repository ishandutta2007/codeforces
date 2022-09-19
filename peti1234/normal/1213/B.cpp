#include <bits/stdc++.h>

using namespace std;
int w, n, t[200002], db, mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, db=1;
        for (int i=1; i<=n; i++) cin >> t[i];
        mini=t[n];
        for (int i=n-1; i>=1; i--) {
            if (t[i]<=mini) db++, mini=t[i];
        }
        cout << n-db << "\n";
    }
    return 0;
}