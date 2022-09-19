#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long a, b, x=1;
    cin >> a >> b;

    for (int i=1; i<=min(a, b); i++) x*=i;
    cout << x << endl;
    return 0;
}