#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int sum(long long int a)
{
    int ans=0;
    while(a)
    {
        ans+=a%10;
        a/=10;
    }
    return ans;
}

int main()
{
    long long int n; cin>>n;
    int ans=0;
    long long x=9;
    int i=1;
    while(x*10+9<n)
    {
        x*=10; x+=9;
        i++;
    }
    cout<<i*9+sum(n-x);



    return 0;
}