#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,k; cin>>n>>k;
    long long int res=0;
    res++;
    if(k>=2) res+=(n)*(n-1)/2;
    if(k>=3) res+=(n)*(n-1)*(n-2)/3;
    if(k==4) res+=(n)*(n-1)*(n-2)*(n-3)/24*9;
    cout<<res;
    return 0;
}