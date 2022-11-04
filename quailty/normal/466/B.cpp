#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>v;
int main()
{
    ll n,a,b,t;
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    n*=6;
    for(t=1;(t+1)*(t+1)<=n;t++)
        v.push_back(t);
    for(ll i=n/t;i>=1;i--)
        v.push_back((n+i-1)/i);
    ll res=~0ULL>>1,ra=0,rb=0;
    for(int i=0;i<(int)v.size();i++)
    {
        ll ta=max(a,v[i]),tb=max(b,(n+ta-1)/ta);
        if(ta*tb<res)
        {
            res=ta*tb;
            ra=ta;
            rb=tb;
        }
    }
    printf("%I64d\n%I64d %I64d\n",res,ra,rb);
    return 0;
}