#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
pair<ll,ll> operator + (pair<ll,ll>a,pair<ll,ll>b)
{
    return make_pair(a.first+b.first,a.second+b.second);
}
map<ll,pair<ll,ll> >mp;
pair<ll,ll> dfs(ll x)
{
    if(mp.find(x)!=mp.end())return mp[x];
    if(x==0)return make_pair(0,0);
    ll l=1,r=100000;
    while(l<r)
    {
        ll m=(l+r+1)>>1;
        if(m*m*m<=x)l=m;
        else r=m-1;
    }
    ll k=l*l*l;
    return mp[x]=max(dfs(x%k)+make_pair(x/k,x/k*k),
               dfs(k-1)+make_pair(x/k-1,(x/k-1)*k));
}
int main()
{
    ll m;
    scanf("%I64d",&m);
    pair<ll,ll>res=dfs(m);
    printf("%I64d %I64d\n",res.first,res.second);
    return 0;
}