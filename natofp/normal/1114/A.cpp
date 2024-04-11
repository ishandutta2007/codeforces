#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,z; cin>>x>>y>>z;
    int a,b,c;cin>>a>>b>>c;
    if(a<x) {cout<<"NO"; return 0;}
    else a-=x;
    if((a+b)<y) {cout<<"NO"; return 0;}
    else
    {
        if(a>y) a-=y;
        else {
        y-=a;
        a=0;
        b-=y;
        }
    }
    if((a+b+c)>=z) {cout<<"YES";}
    else cout<<"NO";
    return 0;
}