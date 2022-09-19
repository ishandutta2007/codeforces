#include <bits/stdc++.h>

using namespace std;
long long a, b, c, d, e, x, y, o=0;
int main()
{
    cin >> a >> b >> c >> d >> e;
    x=2*c+d, y=3*e+d;
    cout << max(o, x-a)+max(o, y-b) << "\n";
    return 0;
}