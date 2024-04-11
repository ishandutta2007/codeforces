#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], db[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, ans=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            db[t[i]]++;
        }
        for (int i=1; i<=2*n+1; i++) {
            if (db[i]) {
                ans++;
            }
            if (db[i]>1) {
                db[i+1]++;
            }
        }
        for (int i=1; i<=n; i++) {
            db[t[i]]=0, db[t[i]+1]=0;
        }
        cout << ans << "\n";
    }
    return 0;
}