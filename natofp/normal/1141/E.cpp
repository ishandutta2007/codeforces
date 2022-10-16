#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int main()
{
    long long int h,n; cin>>h>>n;
    vector<long long int> a;
    for(int i=0;i<n;i++)
    {
        long long int x; cin>>x;
        a.push_back(x);
    }
    long long int bilans=0;
    for(int i=0;i<n;i++)
    {
        bilans+=a[i];
    }
    long long int t=h;
    for(int i=0;i<n;i++)
    {
        t+=a[i];
        if(t<=0)
        {
            cout<<i+1; return 0;
        }
    }
    if(bilans>=0)
    {
        cout<<-1;
        return 0;
    }
    long long int naj=0;
    long long int minn=0;

    for(int i=0;i<n;i++)
    {
        naj+=a[i];
        if(naj<minn)
        {
            minn=naj;
        }
    }
    h+=minn;
    bilans*=-1;
    long long int ans=0;
    long long ile=h/bilans;
    ans+=(ile-1)*n;
    h-=(ile-1)*bilans;
    h-=minn;
    long long int i=1;
    t=1;
    while(true)
    {
        h+=a[i-1];
        if(h<=0) {cout<<ans+t<<endl; return 0;}
        i++;
        t++;
        if(i==n+1) i=1;

    }
    return 0;
}