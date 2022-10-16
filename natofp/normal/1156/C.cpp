#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,z;
vector<int> a;

bool czy(int ile)
{
    if(ile==0) return true;
    for(int i=0;i<ile;i++)
    {
        if(a[n-ile+i]-a[i]<z) return false;
    }
    return true;
}

int main()
{
    cin>>n>>z;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int lo=0;
    int hi=n/2;
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        bool ok =czy(mid);
        if(ok) lo=mid;
        else hi=mid;
    }
    if(czy(hi)==true) cout<<hi;
    else cout<<lo;
    return 0;
}