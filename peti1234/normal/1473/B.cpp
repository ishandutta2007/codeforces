#include <bits/stdc++.h>

using namespace std;
int w, x, y, p;
string a, b, c, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b, x=a.size(), y=b.size();
        p=x*y/__gcd(x, y);
        c.clear(), d.clear();
        for (int i=1; i<=p/x; i++) {
            c+=a;
        }
        for (int i=1; i<=p/y; i++) {
            d+=b;
        }
        if (c==d) {
            cout << c << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}