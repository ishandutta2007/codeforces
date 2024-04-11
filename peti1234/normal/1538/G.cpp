#include <bits/stdc++.h>

using namespace std;
long long w, x, y, a, b, ans, db1, db2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> x >> y >> a >> b;
        if (y>x) {
            swap(x, y);
        }
        if (b>a) {
            swap(b, a);
        }
        if (a==b) {
            cout << y/a << "\n";
        } else {
            db1=min((x-y)/(a-b), y/b);
            x-=a*db1, y-=b*db1;
            db2=y/(a+b);
            x-=db2*(a+b), y-=db2*(a+b);
            ans=db1+2*db2;
            if (x>=a && y>=b) {
                ans++;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}