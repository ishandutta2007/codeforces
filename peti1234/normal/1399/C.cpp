#include <bits/stdc++.h>

using namespace std;
int n, db[102], maxi, cnt, w;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, maxi=0;
        for (int i=1; i<=2*n; i++) db[i]=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            db[x]++;
        }
        for (int i=1; i<=2*n; i++) {
            cnt=0;
            for (int k=1; k<=i; k++) cnt+=min(db[k], db[i-k]);
            maxi=max(maxi, cnt/2);
        }
        cout << maxi << "\n";
    }
    return 0;
}