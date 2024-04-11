#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    long long int ile=a[2]-a[1];
    long long int ans=0;
    if(a[0]>=ile/2)
    {
        cout<<(a[0]+a[1]+a[2])/3; return 0;
    }
    ans+=a[0];
    a[2]-=2*a[0];
    if(a[2]<=2*a[1])
    {
        ans+=(a[2]+a[1])/3;
    }
    else ans+=a[1];
    cout<<ans;
    return 0;
}