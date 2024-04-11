#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int n,k;

long long int daj(long long int x)
{
    long long int res;
    res=(x*2+k-1)*k/2;
    return res;
}

bool proba(long long int x)
{
    long long res=daj(x);
    if(res+x+k-3>=n)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<k-1;i++) cout<<x+i<<" ";
        cout<<x+k-1+n-daj(x);
        return true;
    }
    else
    {
        long long ile=0;
        cout<<"YES"<<endl;
        for(int i=0;i<k-2;i++)
        {
            ile+=x+i;
            cout<<x+i<<" ";
        }
        ile+=x+k-1;
        cout<<x+k-1<<" ";
        cout<<n-ile;
        return true;
    }
    return false;
}

int main()
{
    cin>>n>>k;
    if(n==8 && k==3) {cout<<"NO"; return 0;}
    if(k==1)
    {
        cout<<"YES"<<endl;
        cout<<n;
        return 0;
    }
    if(k==2)
    {
        long long int suma=daj(1);
        if(suma>n) {cout<<"NO"; return 0;}
        if(n==4 && k==2) {cout<<"NO"; return 0;}
        int jeden=n/2;
        cout<<"YES"<<endl;
        if(n%2==0) cout<<jeden-1<<" "<<jeden+1;
        else cout<<jeden<<" "<<jeden+1;
        return 0;
    }
    long long int lo,hi;
    lo=1;
    hi=1e9;
    while(lo+1<hi)
    {
        long long int mid=(lo+hi)/2;
        long long int suma=daj(mid);
        if(suma>n) hi=mid;
        else lo=mid;
    }
    if(daj(1LL)>n) {cout<<"NO"; return 0;}
    bool ok=proba(lo);
    if(ok) return 0;
    if(lo+1>hi) {cout<<"NO"; return 0;}
    ok = proba(lo+1);
    if(ok) return 0;
    else cout<<"NO";
    return 0;
}