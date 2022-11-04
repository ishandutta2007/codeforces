#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
void check(ll n,ll k,ll g)
{
    ll t=n/g;
    if(k*(k+1)/2<=t)
    {
        for(int i=1;i<k;i++)
            printf("%lld ",i*g),t-=i;
        printf("%lld",t*g);
        exit(0);
    }
}
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    k=min(k,200000LL);
    vector<ll> f;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i!=0)continue;
        f.push_back(i);
        if(i*i<n)f.push_back(n/i);
    }
    sort(f.begin(),f.end(),greater<ll>());
    for(int i=0;i<(int)f.size();i++)
        check(n,k,f[i]);
    return 0*printf("-1");
}