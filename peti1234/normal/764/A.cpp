#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << c/(a*b/__gcd(a,b)) << endl;
    return 0;
}