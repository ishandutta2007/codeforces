#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y,b,r; cin>>y>>b>>r;

    if(r<=b)
    {
        b=r-1;
    }
    else
    {
        r=b+1;
    }
    if(b<=y)
    {
        y=b-1;
    }
    else
    {
        b=y+1;
        r=b+1;
    }
    cout<<r+b+y;
    return 0;
}