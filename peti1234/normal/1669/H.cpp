#include <bits/stdc++.h>

using namespace std;
int w, n, k, db[31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            for (int j=0; j<=30; j++) {
                if ((x & (1<<j))==0) {
                    db[j]++;
                }
            }
        }
        int ans=0;
        for (int i=30; i>=0; i--) {
            if (db[i]<=k) {
                k-=db[i];
                db[i]=0;
            }
            if (db[i]==0) ans+=(1<<i);
            db[i]=0;
        }
        cout << ans << "\n";
    }
    return 0;
}