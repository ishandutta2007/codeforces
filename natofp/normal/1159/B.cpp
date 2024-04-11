#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    long long int * a=new long long int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    long long int res=1e18;
    for(int i=1;i<=n;i++)
    {
        long long t;
        t=a[i];
        t/=max(i-1,n-i);
        res=min(t,res);
    }
    cout<<res;
    return 0;
}