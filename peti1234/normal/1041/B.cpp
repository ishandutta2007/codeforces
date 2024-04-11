#include <bits/stdc++.h>

using namespace std;
long long a, b, x, y;
long long gcd(long long x, long long y)
{
    if (y>x) {
        swap(x, y);
    }
    if (y==0) {
        return x;
    }
    return gcd(y, x%y);
}
int main()
{
    cin >> a >> b >> x >> y;
    long long c=gcd(x, y);
    x/=c;
    y/=c;

    cout << min(a/x, b/y);
    return 0;
}