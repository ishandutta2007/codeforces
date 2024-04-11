#include <bits/stdc++.h>

using namespace std;
long long n, m;
long long k;
 main()
{
    cin >> n >> m;
    if (m>=n) {
        cout << n << endl;
        return 0;
    }
    k=m;
    long long p=2*n-2*m;
    k+=sqrt(p);
    long long z=sqrt(p);
    if (z*z+z<p) {
        k++;
    }
    cout << k << endl;
    return 0;
}