#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll nax=2e5+5;
const ll mod=998244353;
ll k;
ll a[nax];
ll n;
ll s[nax];
ll popo[nax];
ll xdd[nax];
ll dwa[nax];

void prep()
{
    s[0]=1;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]*i;
        s[i]%=mod;

    }
    popo[0]=1;
    for(int i=1;i<nax;i++)
    {
        popo[i]=popo[i-1]*k;
        popo[i]%=mod;
    }
    xdd[0]=1;
    for(int i=1;i<nax;i++)
    {
        xdd[i]=xdd[i-1]*(k-2);
        xdd[i]%=mod;
    }
   dwa[0]=1;
    for(int i=1;i<nax;i++)
    {
        dwa[i]=dwa[i-1]*2LL;
        dwa[i]%=mod;
    }
}

ll pot(ll a,ll b)
{
    if(b==0) return 1LL;
    ll res=pot(a,b/2);
    res*=res;
    res%=mod;
    if(b%2==1) res*=a;
    res%=mod;
    return res;
}

ll odw(ll a)
{
    return pot(a,mod-2);
}

ll nk(ll a,ll b)
{
    ll res=s[a];
    res%=mod;
    res*=odw(s[b]);
    res%=mod;
    res*=odw(s[a-b]);
    res%=mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    if(k==1)
    {
        cout<<0; return 0;
    }
    if(n==1)
    {
        cout<<0; return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    prep();
    ll ile=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i%n+1]) ile++;
    }
    ll pula=n-ile;
    ll res=popo[ile];
    ll rest=0;
    for(int i=1;i<=pula;i++)
    {
        ll akt=nk(pula,i);
        ll podz=dwa[i];
        ll row=0;
        if(i%2==0)
        {
            row=nk(i,i/2);
        }
        podz-=row;
        if(podz<0) podz+=mod;
        podz*=odw(2);
        podz%=mod;
        akt*=podz;
        akt%=mod;
        akt*=xdd[pula-i];
        akt%=mod;
        rest+=akt;
        rest%=mod;
    }
    res*=rest;
    res%=mod;
    cout<<res;

    return 0;
}