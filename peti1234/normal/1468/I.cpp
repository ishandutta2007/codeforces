#include <bits/stdc++.h>

using namespace std;
long long n, a, b, c, d;
int main()
{
    cin >> n >> a >> b >> c >> d;
    if (abs(a*d-b*c)!=n) {
        cout << "NO\n";
        return 0;
    }
    if (a<0) {
        a=-a, b=-b;
    }
    if (c<0) {
        c=-c, d=-d;
    }
    while(a && c) {
        if (a>c) {
            int db=a/c;
            a-=db*c, b-=db*d;
        } else {
            int db=c/a;
            c-=db*a, d-=db*b;
        }
    }
    if (!a) {
        d=0;
    } else {
        b=0;
    }
    cout << "YES\n";
    b=abs(b), d=abs(d);
    for (int i=1; i<=max(a, c); i++) {
        for (int j=1; j<=max(b, d); j++) {
            cout << i << " " << j << "\n";
        }
    }
    return 0;
}