#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int res1;
    int res2;
    res1=abs(a-b)*d;
    res2=3*f;

    res2+=abs(a-c)*e;
    res2+=abs(a-b)*e;
    if(res2<=res1) cout<<"YES";
    else cout<<"NO";
    return 0;
}