#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int naj(int * tab,int n,int k)
{
    int wyn=1000000001;
    for(int i=0;i<n;i++)
    {
        if(tab[i]<wyn && i!=k) wyn=tab[i];
    }
    return wyn;
}

int najw(int * tab,int n,int k)
{
    int wyn=-1000000001;
    for(int i=0;i<n;i++)
    {
        if(tab[i]>wyn && i!=k) wyn=tab[i];
    }
    return wyn;
}

int najj(int * tab,int n,int k)
{
    int wyn=1000000001;
    int ind=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i]<wyn && i!=k) {wyn=tab[i]; ind=i;}
    }
    return ind;
}

int najwj(int * tab,int n,int k)
{
    int wyn=-1000000001;
    int ind=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i]>wyn && i!=k) {wyn=tab[i]; ind=i;}
    }
    return ind;
}

int main()
{
    int n;
    cin>>n;
    int * a;
    int * b;
    int * c;
    int * d;
    a=new int[n];
    b=new int[n];
    c=new int[n];
    d=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    int e,f,g,h;
    int tab[4];
    tab[0]=najj(d,n,-1);
    tab[1]=najj(c,n,-1);
    tab[2]=najwj(a,n,-1);
    tab[3]=najwj(b,n,-1);

    for(int i=0;i<4;i++)
    {
    e=najw(a,n,tab[i]);
    f=najw(b,n,tab[i]);
    g=naj(c,n,tab[i]);
    h=naj(d,n,tab[i]);
    if(e<=g && f<=h) {cout<<e<<" "<<f; return 0;}
    }

    return 0;
}