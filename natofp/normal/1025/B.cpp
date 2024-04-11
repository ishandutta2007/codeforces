#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

struct para
{
    int a;
    int b;
};

int main()
{
    int n; cin>>n;
    para * a;
    a=new para[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].a;
        cin>>a[i].b;
    }
    int x,y;
    x=a[0].a;
    y=a[0].b;
    vector<int> odp;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            odp.push_back(i);
            x/=i;
            i--;
        }
    }
    odp.push_back(x);
    for(int i=2;i<=sqrt(y);i++)
    {
        if(y%i==0)
        {
            odp.push_back(i);
            y/=i;
            i--;
        }
    }
    odp.push_back(y);
    bool xd;
    for(int i=0;i<odp.size();i++)
    {
        int t=odp[i];
        xd=true;
        for(int j=0;j<n;j++)
        {
            if(a[j].a%t==0 || a[j].b%t==0) continue;
            else {xd=false; break;}
        }
        if(xd)
        {
            cout<<t; return 0;
        }
    }
    cout<<-1;





    return 0;
}