#include <bits/stdc++.h>

using namespace std;
long long sum, db, p, n, k, a, b;
int main()
{
    cin >> n >> k;
    if (n%2==0) p=n/2;
    for (int i=1; i<=k; i++) {
        cin >> a >> b;
        sum+=a*b, db+=b;
    }
    if (db+(sum%n!=p)<=n) cout << 1;
    else cout << -1;
    return 0;
}