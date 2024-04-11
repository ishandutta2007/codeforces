#include <bits/stdc++.h>

using namespace std;
long long x, y;
int main()
{
    cin >> x, x=abs(x), y=sqrt(2*x);
    while(y*(y+1)<2*x || (y*(y+1)/2-x)%2) y++;
    cout << y << endl;
    return 0;
}