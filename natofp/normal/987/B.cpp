#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    if (x==y || (x==2 && y==4) || (x==4 && y==2)) cout<<"=";
    else if(y*log(x)>x*log(y)) cout<<">";

    else cout<<"<";
    return 0;
}