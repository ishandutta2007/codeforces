#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,m,k; cin>>n>>m>>k;
    long long int res=0;
    long long int * a=new long long int [n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long int ile=k*a[n-1]+a[n-2];
    res+=(m/(k+1))*ile;
    m%=(k+1);
    res+=m*a[n-1];
    cout<<res;
    return 0;
}