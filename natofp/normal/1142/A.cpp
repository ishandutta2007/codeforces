#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int minn=1e18;
    long long  maxx=-1e18;
    long long  t[4];
    long long int n,k,a,b; cin>>n>>k>>a>>b;
    t[0]=k-a+b;
    t[1]=a+b;
    t[2]=k-a+k-b;
    t[3]=a+k-b;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            long long res=(long long int)j*k+t[i];
            long long ile=n*k/__gcd(res,n*k);
            minn=min(minn,ile);
            maxx=max(maxx,ile);
        }
    }
    cout<<minn<<" "<<maxx;
    return 0;
}