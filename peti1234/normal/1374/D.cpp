#include <bits/stdc++.h>

using namespace std;
int w, n;
long long db, k, maxi;
int t[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, db=0, maxi=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            t[i]=k-x%k;
        }
        sort(t+1, t+n+1), t[0]=-1, t[n+1]=-1;
        for (int i=1; i<=n+1; i++) {
            if (t[i]!=t[i-1] && t[i-1]!=k) maxi=max(maxi, (db-1)*k+t[i-1]), db=0;
            if (t[i]!=t[i-1]) db=0;
            db++;
        }
        if (maxi) maxi++;
        cout << maxi << "\n";
    }
    return 0;
}