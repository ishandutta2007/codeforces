#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,n;
    cin>>n>>k;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1) x++;
        else y++;
    }
    for(int i=0;i<k;i++)
    {
        int ile1,ile2;
        ile1=x;
        ile2=y;
        for(int j=i;j<n;j+=k)
        {
            if(a[j]==1) ile1--;
            else ile2--;
        }
        ans=max(ans,abs(ile1-ile2));
    }
    cout<<ans;
    return 0;
}