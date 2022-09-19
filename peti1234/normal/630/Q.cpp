#include <bits/stdc++.h>

using namespace std;
long double a, b, c, t, r, m, sum;
long double s1=2, s2=5, pi=3.14159265359;
int main()
{
    cin >> a >> b >> c;
    sum+=a*a*a*sqrt(s1)/12;
    sum+=b*b*b*sqrt(s1)/6;
    t=c*c*sqrt(25+10*sqrt(s2));
    r=c/2/cos(pi*3/10);
    m=sqrt(c*c-r*r);
    sum+=t*m/12;
    cout.precision(20);
    cout << sum << "\n";
    return 0;
}