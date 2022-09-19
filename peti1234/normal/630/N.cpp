#include <bits/stdc++.h>

using namespace std;
long double a, b, c, x, y;
int main()
{
    cin >> a >> b >> c;
    cout.precision(20);
    x=(-b+sqrt(b*b-4*a*c))/2/a, y=(-b-sqrt(b*b-4*a*c))/2/a;
    cout << max(x, y) << "\n" << min(x, y) << "\n";
    return 0;
}