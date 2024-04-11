#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,k;
const int nax=2e5+5;
long long int a[nax];
int xd;

bool czy(long long int mid)
{
    if(a[xd]>=mid) return true;
    long long int res=0;
    for(int i=xd;i<=n;i++)
    {
        res+=max(0LL,mid-a[i]);
        if(res>k) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    xd=n/2+1;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    long long int lo=0;
    long long int hi=(long long int)2e9;
    while(lo+1<hi)
    {
        long long int mid=(lo+hi)/2;
        bool ok =czy(mid);
        if(ok)
        {
            lo = mid;
        }
        else hi=mid;
    }
    if(czy(lo+1))
    {
        cout<<lo+1;
    }
    else cout<<lo;
    return 0;
}