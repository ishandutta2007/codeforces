#include <bits/stdc++.h>

using namespace std;
long long a=1, b, c;
long long mod=1000000007;
int n, l, r;
long long x, y, z;
int main()
{
    cin >> n >> l >> r;
    l--;
    long long ccc=(r-l)/3;
    x+=ccc, y+=ccc, z+=ccc;
    r-=3*ccc;
    l++;
    for (int i=l; i<=r; i++) {
        if (i%3==0) {
            x++;
        }
        if (i%3==1) {
            y++;
        }
        if (i%3==2) {
            z++;
        }
    }
    for (int i=1; i<=n; i++) {
        long long aa=a, bb=b, cc=c;
        a=(aa*x+bb*z+cc*y)%mod;
        b=(aa*y+bb*x+cc*z)%mod;
        c=(aa*z+bb*y+cc*x)%mod;
        //cout << a << " " << b << " " << c << endl;
    }
    cout << a << endl;
    return 0;
}