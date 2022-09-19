#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, e, f, x, y;
int main()
{
    cin >> a >> b >> c >> d >> e >> f;
    x=abs(a-c), y=abs(b-d);
    cout << (x%e || y%f || (x/e+y/f)%2 ? "NO" : "YES") << "\n";
    return 0;
}