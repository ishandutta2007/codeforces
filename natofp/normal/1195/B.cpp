#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,k; cin>>n>>k;
    long long int lo=0;
    long long int hi=n;
    while(lo+1<hi)
    {
        long long int mid=(lo+hi)/2;
        long long int ile=(1+mid)*mid/2;
        long long int jem=n-mid;
        ile-=jem;
        if(ile>k) hi=mid;
        else lo=mid;
    }

    long long int ile=(lo+1)*lo/2;
    long long int jem=n-lo;
    ile-=jem;
    if(ile==k)
    {
        cout<<jem<<endl; return 0;
    }

    lo++;
    ile=(lo+1)*lo/2;
     jem=n-lo;
    cout<<jem;
    return 0;
}