#include <bits/stdc++.h>
using namespace std;
long long xl,xr,yl,yr,x,y,n;

int main()
{
    cin >> n;
    xl=1000000000;
    yl=1000000000;
    xr=-1000000000;
    yr=-1000000000;
    while(n--)
    {
        cin >> x>>y;
        xl=min(xl,x);
        yl=min(yl,y);
        xr=max(x,xr);
        yr=max(y,yr);
    }
    cout << max((xr-xl),(yr-yl))*max((xr-xl),(yr-yl));
    return 0;
}