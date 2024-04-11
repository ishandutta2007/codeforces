#include <bits/stdc++.h>

using namespace std;
long double n, r, pi=3.14159265359, sz, sz2;
int main()
{
    cin >> n >> r;
    sz=pi/n, sz2=sz/2;
    cout.precision(20);
    cout << r*r/(1/tan(sz)+1/tan(sz2))*n << endl;
    return 0;
}