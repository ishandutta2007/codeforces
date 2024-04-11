#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n%2==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=0)
            {
                a[i]=-a[i]-1;
            }
            cout<<a[i]<<" ";
        }
        return 0;
    }
    int maxx=-1e9-5;
    int idx;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<0) a[i]=-a[i]-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>maxx)
        {
            maxx=a[i];
            idx=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(idx==i)
        {
            cout<<a[i]<<" ";
        }
        else cout<<-a[i]-1<<" ";
    }
    return 0;
}