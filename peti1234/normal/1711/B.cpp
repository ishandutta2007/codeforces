#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, m, db[c], t[c], l[c], r[c], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) cin >> t[i], sum+=t[i];
        for (int i=1; i<=m; i++) {
            cin >> l[i] >> r[i];
            db[l[i]]++, db[r[i]]++;
        }
        if (m%2==0) {
            cout << 0 << "\n";
        } else {
            int mini=sum;
            for (int i=1; i<=n; i++) {
                if (db[i]%2) mini=min(mini, t[i]);
            }
            for (int i=1; i<=m; i++) {
                int x=l[i], y=r[i];
                if (db[x]%2 == db[y]%2) mini=min(mini, t[x]+t[y]);
            }
            cout << mini << "\n";
        }
        sum=0;
        for (int i=1; i<=n; i++) t[i]=0, db[i]=0;
        for (int i=1; i<=m; i++) l[i]=0, r[i]=0;
    }
    return 0;
}