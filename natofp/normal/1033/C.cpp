#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct liczba
{
    int nr;
    int val;
};

bool por(liczba a,liczba b)
{
    return a.val>b.val;
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    liczba * a;
    a=new liczba[n];
    int * b;
    b=new int[n];
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        b[i]=x;
        liczba xd;
        xd.nr=i;
        xd.val=x;
        a[i]=xd;
    }
    bool * odp;
    odp=new bool[n+1];
    for(int i=0;i<=n;i++) odp[i]=0;
    sort(a,a+n,por);
    for(int i=0;i<n;i++)
    {
        int t=a[i].nr;
        int start=t%(n-i);
        bool xd=false;
        for(int j=start;j<n;j+=(n-i))
        {
            if(b[j]>n-i &&odp[b[j]]==false && j!=t) xd=true;
        }
        if(xd) odp[n-i]=true;

    }
    for(int i=0;i<n;i++)
    {
        if(odp[b[i]]==true) cout<<"A";
        else cout<<"B";
    }
    return 0;
}