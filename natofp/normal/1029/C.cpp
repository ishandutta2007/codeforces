#include <iostream>
#include <bits/stdc++.h>
using namespace std;



struct xd
{
    int a;
    int b;
};

int get(xd * a,int n,int roz)
{
    int o=-1;
    int p=1000000001;
    for(int i=0;i<roz;i++)
    {
        if(i==n) continue;
        else
        {
            o=max(o,a[i].a);
            p=min(p,a[i].b);
        }
    }
    return p-o;
}

int main()
{
    int n;
    cin>>n;
    xd * a;
    a=new xd[n];
    int x,y;
    cin>>a[0].a;
    cin>>a[0].b;
    x=a[0].a;
    y=a[0].b;
    int c,d;
    c=0;
    d=0;
    for(int i=1;i<n;i++)
    {
        cin>>a[i].a;
        cin>>a[i].b;
        if(a[i].a>x) {x=a[i].a; c=i;}
        if(a[i].b<y) {y=a[i].b; d=i;}
    }
    int naj=get(a,-1,n);
    naj=max(naj,get(a,c,n));
    naj=max(naj,get(a,d,n));
    cout<<max(naj,0);

    return 0;
}