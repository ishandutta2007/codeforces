#include <bits/stdc++.h>

using namespace std;
int a, b, c, d;
long long lenyeg=0;
int main()
{
    cin >> a >> b >> c >> d;
    lenyeg+=min(a, min(c, d) )*256;
    a-=min(a, min(c, d) );




    lenyeg+=min(a, b)*32;

    cout << lenyeg << endl;

    return 0;
}