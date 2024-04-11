#include <bits/stdc++.h>

using namespace std;
long long n, m, ert, q, a1, a2, b1, b2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    ert=__gcd(n, m);
    n/=ert, m/=ert;
    while (q--) {
        cin >> a1 >> b1 >> a2 >> b2;
        b1--, b2--;
        if (a1==1) b1/=n;
        else b1/=m;
        if (a2==1) b2/=n;
        else b2/=m;

        cout << (b1==b2 ? "YES" : "NO") << "\n";
    }
    return 0;
}