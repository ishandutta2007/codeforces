#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    cin >> q;
    for (int i=1; i<=q; i++) {
        long long p;
        cin >> p;
        long long x=0;
        long long y=1;
        while(x<p) {
            x+=y;
            y*=2;
        }
        long long f=sqrt(x+1);
        if (x==p) {
            for (int i=2; i<=f; i++) {
                if ((x%i)==0) {
                    cout << x/i << endl;
                    break;
                }
                if (i==f) {
                    cout << 1 << endl;
                }
            }
        } else {
            cout << x << endl;
        }
    }
    return 0;
}