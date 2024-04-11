#include <bits/stdc++.h>

using namespace std;
int a, b, c, m, p, q, r, d, e, f;
int x=20000;
void ch() {
    if (abs(c-d)+abs(e-b)+abs(f-a)<m) m=abs(c-d)+abs(e-b)+abs(f-a), p=f, q=e, r=d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while(w--) {
        cin >> a >> b >> c;
        m=c-a, p=b, q=b, r=b;
        for (int i=1; i<=x; i++) {
            for (int j=i; j<=x; j+=i) {
                d=c/j*j, e=d/j*i, f=e/i, ch();
                d+=j, e+=i, f+=1, ch();
                d-=2*j, e-=2*i, f-=2;
                if (d>0 && e>0 && f>0) ch();
                f=a, e=f*i, d=f*j, ch();
                e=b/i*i, f=e/i, d=f*j, ch();
                e+=i, f=e/i, d=f*j, ch();
            }
        }
        cout << m << "\n" << p << " " << q << " " << r << "\n";
    }
    return 0;
}