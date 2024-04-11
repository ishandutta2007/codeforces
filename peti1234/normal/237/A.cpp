#include <bits/stdc++.h>

using namespace std;
int db[3002], maxi, n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y, z;
        cin >> x >> y, z=100*x+y;
        db[z]++, maxi=max(maxi, db[z]);
    }
    cout << maxi << "\n";
    return 0;
}