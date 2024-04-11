#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
ll gcd(ll a,ll b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
ll power(ll a,int s)
{
    ll start=a;
    for(int i=1;i<s;i++)
    {
        a*=start;
    }
    return a;
}
vector<ll> podeli(ll a)
{
    //printf("Pozvan za %lld\n",a);
    vector<ll> res;
    ll i1=(ll)pow(a,(long double)1/4);
    ll po=(ll)power(i1,4);
    if(po==a)
    {
        for(int i=0; i<4; i++)
        {
            res.pb(i1);
        }
        return res;
    }
    i1=(ll)pow(a,(long double)1/3);
    po=(ll)power(i1,3);
    if(po==a)
    {
        for(int i=0; i<3; i++)
        {
            res.pb(i1);
        }
        return res;
    }
    i1=(ll)pow(a,(long double)1/2);
    po=(ll)power(i1,2);
    if(po==a)
    {
        for(int i=0; i<2; i++)
        {
            res.pb(i1);
        }
        return res;
    }
    return res;
}
int main()
{
    ll mod=998244353;
    ll n;
    scanf("%lld",&n);
    map<ll,int> mapa;
    set<ll> sve;
    vector<ll> niz;
    vector<int> done(n);
    for(int i=0; i<n; i++)
    {
        ll a;
        scanf("%lld",&a);
        vector<ll> p=podeli(a);
        niz.pb(a);
        if(p.size()>0)
            done[niz.size()-1]=1;
        for(auto x:p)
        {
            mapa[x]++;
            sve.insert(x);
        }
    }
    for(int i=0; i<niz.size(); i++)
    {
        for(int j=0; j<niz.size(); j++)
        {
            if(niz[i]!=niz[j]&&done[i]==0)
            {
                ll g=gcd(niz[i],niz[j]);
                if(g!=1)
                {
                    done[i]=1;
                    mapa[g]++;
                    sve.insert(g);
                    mapa[niz[i]/g]++;
                    sve.insert(niz[i]/g);
                }
            }
        }
    }
    for(int i=0; i<niz.size(); i++)
    {
        if(done[i]==0)
        {
            mapa[niz[i]]++;
            mapa[LLONG_MAX-niz[i]]++;
            sve.insert(niz[i]);
            sve.insert(LLONG_MAX-niz[i]);
        }
    }
    ll res=1;
    for(auto p:sve)
    {
        res=((ll)res*(ll)(mapa[p]+1))%mod;
    }
    printf("%lld\n",res);
    return 0;
}