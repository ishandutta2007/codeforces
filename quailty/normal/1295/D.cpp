#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll a,m;
        scanf("%lld%lld",&a,&m);
        ll g=__gcd(a,m);
        a/=g,m/=g;
        vector<ll> fac;
        for(ll i=1;i*i<=m;i++)if(m%i==0)
        {
            fac.push_back(i);
            if(i*i<m)fac.push_back(m/i);
        }
        sort(fac.begin(),fac.end());
        vector<ll> cnt(fac.size());
        for(int i=0;i<(int)fac.size();i++)
            cnt[i]=(a+m)/fac[i]-a/fac[i];
        for(int i=(int)fac.size()-1;i>=0;i--)
            for(int j=i+1;j<(int)fac.size();j++)
                if(fac[j]%fac[i]==0)cnt[i]-=cnt[j];
        printf("%lld\n",cnt[0]);
    }
    return 0;
}