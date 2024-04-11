#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct tir
{
    long long int s,f,c,r;
};
const int N=500;
vector<long long int> a(N,0);
int n;

typedef long long ll;
ll ans=1;

bool sprawdz(tir z,ll v)
{
    long long int s,f,c,r;
    s=z.s; f=z.f; c=z.c; r=z.r;
    s--; f--;
    ll akt=v;
    for(int i=s;i<f;i++)
    {
        ll t=a[i+1]-a[i];
        if(akt<t*c)
        {
            r--; akt=v;
            if(r<0) return false;
            if(akt<t*c) return false;
        }
        akt-=t*c;
    }
    return true;
}

void update(tir s)
{
    bool ok=sprawdz(s,ans);
    if(ok) return;
    ll lo,hi;
    lo=ans; hi=1e18;
    while(lo+2<hi)
    {
        ll mid=(lo+hi)/2;
        if(sprawdz(s,mid)==true) hi=mid;
        else lo=mid+1;
    }
    while(sprawdz(s,hi)==true) hi--;
    hi++;
    ans=max(ans,hi);
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int m; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    tir * s=new tir[m];
    for(int i=0;i<m;i++)
    {
        cin>>s[i].s>>s[i].f>>s[i].c>>s[i].r;
    }
    for(int i=m-1;i>=0;i--)
    {
        update(s[i]);
    }
    cout<<ans;
    return 0;
}