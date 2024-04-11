#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> l(n,0);
    vector<int> r(n,0);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            l[i]=0;
        }
        else if(i==1) l[i]=1;
        else
        {
            if(a[i-1]>a[i-2])
            {
                l[i]=l[i-1]+1;
            }
            else
            {
                l[i]=1;
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            r[i]=0;
        }
        else if(i==n-2) r[i]=1;
        else
        {
            if(a[i+1]<a[i+2]) r[i]=r[i+1]+1;
            else r[i]=1;
        }

    }
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        if(i==0 || i==n-1 || a[i-1]+1<a[i+1])
        {
            ans=max(ans,l[i]+r[i]+1);
        }
        ans=max(ans,l[i]+1);
        ans=max(ans,r[i]+1);
    }
    cout<<ans;
    return 0;
}