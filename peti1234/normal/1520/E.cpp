#include <bits/stdc++.h>

using namespace std;
int w, n, db, db2;
string s;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        db=db2=ans=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='*') {
                db++;
            }
        }
        for (int i=0; i<n; i++) {
            if (s[i]=='*') {
                db2++;
            } else {
                ans+=min(db2, db-db2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}