#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,w;
    cin>>n>>w;
    vector <int> c(n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    int a,b;
    a=0; b=0;
    int aktualna=0;
    for(int i=0;i<n;i++)
    {
        aktualna+=c[i];
        if(aktualna>b) b=aktualna;
        if(aktualna<a) a=aktualna;
    }
    b=w-b;
    a=-a;
   if(b-a+1>0) cout<<b-a+1;
   else cout<<0;
    return 0;
}