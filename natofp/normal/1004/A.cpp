#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int odl(int d,int a)
{
    return abs(d-a);
}

int main()
{
    int n,d;
    cin>>n>>d;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    map<int,int> x;
    for(int i=0;i<n;i++)
    {
        int k=a[i]-d;
        bool xd=true;
        for(int j=0;j<n;j++) if(odl(k,a[j])<d) xd=false;
        if(xd) x[k]++;
        k=a[i]+d;
        xd=true;
        for(int j=0;j<n;j++) if(odl(k,a[j])<d) xd=false;
        if(xd) x[k]++;

    }
    cout<<x.size();


    return 0;
}