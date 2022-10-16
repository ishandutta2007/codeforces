#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n;
const int nax=2005;
ll a[nax];

unordered_map<int,int> xd;

bool czy(int k)
{
    xd.clear();
    int ile=0;
    for(int i=k+1;i<=n;i++)
    {
        xd[a[i]]++;
        if(xd[a[i]]==2) ile++;
    }
    if(ile==0) return true;
    for(int i=1;i<=n-k;i++)
    {
        xd[a[i]]++;
        if(xd[a[i]]==2) ile++;
        xd[a[i+k]]--;
        if(xd[a[i+k]]==1) ile--;
        if(ile==0) return true;
    }
    return false;

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int lo=0;
    int hi=n;
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        bool ok = czy(mid);
        if(ok) hi=mid;
        else lo=mid;
    }
    if(czy(lo)) cout<<lo;
    else cout<<hi;
    return 0;
}