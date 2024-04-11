#include <bits/stdc++.h>

using namespace std;
long long n, db[4];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        x/=2, y/=2;
        db[x%2+y%2*2]++;
    }
    cout << n*(n-1)*(n-2)/6-(db[0]*db[1]*db[2]+db[0]*db[1]*db[3]+db[0]*db[2]*db[3]+db[1]*db[2]*db[3]) << "\n";
    return 0;
}