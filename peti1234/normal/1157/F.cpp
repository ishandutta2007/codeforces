#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, db[c], ok, ov, maxi, bal, jobb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        ok=x, ov=x, maxi=1;
        db[x]++;
    }
    for (int i=1; i<=c-1; i++) {
        if (db[i]==1 || db[i] && db[i-1]==0) {
            int cnt=db[i];
            bal=i;
            jobb=i;
            while ((jobb==bal || db[jobb]>1) && db[jobb+1]) {
                jobb++;
                cnt+=db[jobb];
            }
            if (cnt>maxi) {
                maxi=cnt;
                ok=bal, ov=jobb;
            }
        }
    }
    cout << maxi << "\n";
    for (int i=ok; i<=ov; i++) {
        cout << i << " ";
        db[i]--;
    }
    for (int i=ov; i>=ok; i--) {
        for (int j=1; j<=db[i]; j++) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}