#include <bits/stdc++.h>

using namespace std;
int t[200001], lnp, j, db, mini=INT_MAX, n, a, b, c, si;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    n=a+b+c;
    for (int i=1; i<=a; i++) {
        int x;
        cin >> x;
        t[x]=1;
    }
    for (int i=1; i<=b; i++) {
        int x;
        cin >> x;
        t[x]=2;
    }
    for (int i=1; i<=c; i++) {
        int x;
        cin >> x;
        t[x]=3;
    }
    db=n-a;
    mini=db;
    for (int i=n; i>=1; i--) {
        if (t[i]==1) {
            db++;
        } else {
            db--;
        }
        if (t[i]==2) {
            j--;
        } else if (t[i]==3) {
            j++;
            si++;
            lnp=max(lnp, j);
        }
        mini=min(mini, db+si-lnp);
    }
    cout << mini << "\n";
    return 0;
}