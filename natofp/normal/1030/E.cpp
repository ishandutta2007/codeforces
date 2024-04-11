#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ile(long long int a)
{
    int ans=0;
    while(a)
    {
        if(a%2==1) ans++;
        a/=2;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    long long int * a;
    a=new long long int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int * b;
    b=new int[n];
    for(int i=0;i<n;i++)
    {
        b[i]=ile(a[i]);
    }
    int * pre;
    pre=new int[n];
    pre[0]=b[0]%2;
    for(int i=1;i<n;i++)
    {
        pre[i]=(pre[i-1]+b[i])%2;
    }
    int ile0=0;
    int ile1=0;
    for(int i=0;i<n;i++)
    {
        if(pre[i]==0) ile0++;
        else ile1++;
    }
    long long int ans=0;
    ans+=ile0;
    for(int i=1;i<n;i++)
    {
        if(pre[i-1]==0) ile0--;
        else ile1--;
        if(pre[i-1]==0) ans+=ile0;
        else ans+=ile1;
    }

    for(int i=0;i<n;i++)
    {
        int j=i;
        int naj=0;
        int sum=0;
        while(j<n && sum<=128)
        {
            naj=max(naj,b[j]);
            sum+=b[j];
            if(naj>(sum-naj))
            {
                if(i==0)
                {
                    if(pre[j]==0) ans--;
                }
                else
                {
                    if(pre[j]-pre[i-1]==0) ans--;
                }
            }

            j++;
        }
    }

    cout<<ans;
    return 0;
}