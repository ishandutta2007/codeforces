#include <bits/stdc++.h>

using namespace std;
int w, n, ans, db, x;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> db >> ans;
        for (int i=1; i<n; i++) {
            int x; cin >> x;
            int mini=min(db/i, x);
            ans+=mini, db-=mini*i;
        }
        cout << ans << "\n";
    }
    return 0;
}