#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int x,y,z;
    cin>>x>>y>>z;
    long long int akt=x/z+y/z;
    long long int ile=(x+y)/z;
    if(ile==akt)
    {
        cout<<ile<<" "<<0<<endl;
        return 0;
    }
    cout<<ile<<" ";
    long long xd=x%z;
    long long xd2=y%z;
    cout<<min(z-xd,z-xd2);
    return 0;
}