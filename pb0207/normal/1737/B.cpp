#include<bits/stdc++.h>
using namespace std;

int T;

long long calc(long long x)
{
    long long ret=0;
    long long l=0,r=1e9+10;
    while(r-l>1)
    {
        long long mid=(l+r)>>1;
        if(mid*mid<=x)
            l=mid;
        else
            r=mid;
    }  
    ret+=l;  
    l=0,r=1e9+10;
    while(r-l>1)
    {
        long long mid=(l+r)>>1;
        if(mid*(mid+1)<=x)
            l=mid;
        else
            r=mid;
    }  
    ret+=l;
    l=0,r=1e9+10;
    while(r-l>1)
    {
        long long mid=(l+r)>>1;
        if(mid*(mid+2)<=x)
            l=mid;
        else
            r=mid;
    }  
    ret+=l;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        long long l,r;
        cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<"\n";
    }
}