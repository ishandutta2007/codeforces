#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    int b,g,n; cin>>b>>g>>n;
    int res=0;
    for(int i=0;i<=min(b,n);i++)
    {
        int bois=i;
        int girls=n-i;
        if(bois<=b && girls<=g) res++;
    }
    cout<<res;
    return 0;
}