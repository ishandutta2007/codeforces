#include <bits/stdc++.h>

using namespace std;
const int sok=1000000002;
int n, k, t[200002], e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> t[i];
    int x=0, y=sok;
    while(y-x>1) {
        int z=(x+y)/2, db=0;
        for (int i=1; i<=n; i++) if ((db%2==0 && t[i]<=z) || db%2) db++;
        if (db>=k) y=z;
        else x=z;
    }
    e=y;
    x=0, y=sok;
    while(y-x>1) {
        int z=(x+y)/2, db=0;
        for (int i=1; i<=n; i++) if ((db%2 && t[i]<=z) || db%2==0) db++;
        if (db>=k) y=z;
        else x=z;
    }
    cout << min(e, y) << endl;
    return 0;
}