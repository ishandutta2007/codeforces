#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >v;
int main()
{
    ll x;
    scanf("%I64d",&x);
    v.clear();
    for(ll n=1,tot=0;tot+n*n<=x;n++)
    {
        tot+=n*n;
        if((6*x)%(n*(n+1))==0)
        {
            ll t=(6*x)/(n*(n+1));
            t+=n-1;
            if(t%3==0)
            {
                ll m=t/3;
                v.push_back(make_pair(n,m));
                if(n!=m)v.push_back(make_pair(m,n));
            }
        }
    }
    sort(v.begin(),v.end());
    printf("%d\n",(int)v.size());
    for(int i=0;i<(int)v.size();i++)
        printf("%I64d %I64d\n",v[i].first,v[i].second);
    return 0;
}