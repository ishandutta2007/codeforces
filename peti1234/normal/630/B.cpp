#include <bits/stdc++.h>

using namespace std;
long long p;
long double a, b=1.000000011;
int main()
{
    cin >> a >> p;
    while(p) {
        if (p%2) a*=b;
        b*=b;
        p/=2;
    }
    cout.precision(20);
    cout << a << "\n";
    return 0;
}