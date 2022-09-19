#include <bits/stdc++.h>

using namespace std;
int w, n, t[100002], maxi, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, maxi=0, db=0;
        for (int i=1; i<=n; i++) t[i]=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            t[x]++;
            if (t[x]>maxi) maxi=t[x], db=0;
            db+=(t[x]==maxi);
        }
        cout << (n-db)/(maxi-1)-1 << "\n";
    }
    return 0;
}