#include <bits/stdc++.h>

using namespace std;
int s=200, ter, lo, hi=8, mid, a, b;
int kerd(int a) {
    cout << "? " << s*(s/a) << "\n";
    for (int i=a; i<=s; i+=a) {
        for (int j=1; j<=s; j++) {
            cout << i << " " << j << " ";
        }
    }
    cout.flush() << endl;
    int x;
    cin >> x;
    return x;
}
int main()
{
    ter=kerd(1);
    a=128, b=ter/128;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        int f=(1<<mid), x=kerd(f);
        if (f*x==ter) {
            lo=mid;
        } else {
            int p=ter/__gcd(ter, x), q=f/2;
            a=p*q/__gcd(p, q);
            b=ter/a;
            hi=mid;
        }
    }
    cout << "! " << 2*(a+b)-4 << "\n";
    return 0;
}