#include <bits/stdc++.h>

using namespace std;
long double h, l;
int main()
{
    cin >> h >> l;
    cout.precision(20);
    cout << (l*l-h*h)/(2*h) << "\n";
    return 0;
}