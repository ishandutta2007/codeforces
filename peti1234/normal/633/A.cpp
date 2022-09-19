#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int a, b, c, d, sa, sb, h;
int main()
{
    cin >> a >> b >> c;
    d=gcd(a, b, sa, sb);
    h=c/d;
    sa*=h, sb*=h;
    if (sa>0) {
        int db=sa*d/b;
        sa-=b/d*db;
        sb+=a/d*db;
    }
    if (sb>0) {
        int db=sb*d/a;
        sb-=a/d*db;
        sa+=b/d*db;
    }
    if (c%d==0 && sa>=0 && sb>=0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}