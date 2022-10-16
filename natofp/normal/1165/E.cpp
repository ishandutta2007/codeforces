#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mod=998244353;

int main()
{
    int n; cin>>n;
    long long int * a=new long long int[n+1];
    long long int * b=new long long int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        long long int mnoznik=(long long int)i*(n-i+1);
        a[i]*=mnoznik;
    }
    sort(b+1,b+1+n);
    sort(a+1,a+1+n);
    long long int res=0;
    for(int i=1;i<=n;i++)
    {
        a[i]%=mod;
        b[n-i+1]%=mod;
        res+=a[i]*b[n-i+1];
        res%=mod;
    }
    cout<<res;
    return 0;
}