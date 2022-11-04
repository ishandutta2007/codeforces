#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll x,vector<ll> &f)
{
    ll res=0;
    int n=(int)f.size();
    for(int i=0;i<(1<<n);i++)
    {
        ll now=1,sgn=1;
        for(int j=0;j<n;j++)
            if(i>>j&1)now*=f[j],sgn*=-1;
        res+=sgn*(x/now);
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll x,p,k;
        scanf("%lld%lld%lld",&x,&p,&k);
        vector<ll> f;
        for(ll i=2;i*i<=p;i++)if(p%i==0)
        {
            f.push_back(i);
            while(p%i==0)p/=i;
        }
        if(p>1)f.push_back(p);
        k+=cal(x,f);
        ll l=1LL,r=1000000000000LL;
        while(l<r)
        {
            ll m=(l+r)/2;
            if(cal(m,f)>=k)r=m;
            else l=m+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}