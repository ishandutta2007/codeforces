#include <bits/stdc++.h>
using namespace std;
long long q, m, d, w, p, n, s, t;
int main()
{
    cin >> q;
    while(q--) {
        cin >> m >> d >> w, p=w/__gcd(w, d-1), n=min(m, d), s=n/p, t=n%p;
        cout << t*s*(s+1)/2+(p-t)*s*(s-1)/2 << "\n";
    }
    return 0;
}