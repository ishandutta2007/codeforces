#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,m; cin>>n>>m;
    if(m%n!=0) {cout<<-1; return 0;}
    int t=m/n;
    int ile3=0;
    int ile2=0;
    while(t%3==0)
    {
        ile3++;
        t/=3;
    }
    while(t%2==0)
    {
        ile2++;
        t/=2;
    }
    if(t!=1) {cout<<-1; return 0;}
    cout<<ile2+ile3;
    return 0;
}