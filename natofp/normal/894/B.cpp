#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod=1000000007;

long long int POW(long long int a,long long int b)
{
    a%=mod;
    if(b==0) return 1;
    if(b==1) return a;
    long long int res=POW(a,b/2)*POW(a,b/2);
    res%=mod;
    if(b%2==1) res*=a;
    res%=mod;
    return res;
}

int main()
{
    long long int n,m,k; cin>>n>>m>>k;
    if(k==1)
    {
        long long int ile=POW(2,n-1);
        ile=POW(ile,m-1);
        cout<<ile;
        return 0;
    }
    else if(k==-1)
    {
        if(n%2==m%2)
        {
            long long int ile=POW(2,n-1);
            ile=POW(ile,m-1);
            cout<<ile;
            return 0;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}