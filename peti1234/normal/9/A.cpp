#include <bits/stdc++.h>

using namespace std;
int a, b, x, y;
int main()
{
    cin >> x >> y;
    x=max(x, y);
    a=6-x+1, b=6;
    for (int i=6; i>=2; i--) if (a%i==0 && b%i==0) a/=i, b/=i;
    cout << a << '/' << b << endl;
    return 0;
}