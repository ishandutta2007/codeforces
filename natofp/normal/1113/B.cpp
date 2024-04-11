#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    int ans=sum;
    int naj=1e9;
    for(int i=0;i<n;i++) naj=min(naj,a[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(a[i]%j==0)
            {
                int t=a[i]/j;
                int mniej=a[i]-t;
                int wiecej=naj*(j-1);
                if(mniej>wiecej)
                {
                    ans=min(ans,sum-mniej+wiecej);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}