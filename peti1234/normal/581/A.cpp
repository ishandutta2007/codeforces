#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int a, b, s;
    cin >> a >> b;
    s=min(a,b);
    cout << s << " " << (a+b-2*s)/2 << endl;
    return 0;
}