#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll Mod=1000000007LL;
map<ll,ll>mp;
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod,k>>=1;
    }
    return res;
}
int main()
{
    ll m,p,s=1,res=1;
    scanf("%I64d",&m);
    while(m--)mp[scanf("%I64d",&p),p]++;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        (s*=(itr->second +1))%=2*Mod-2;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        (res*=fp(itr->first,itr->second*s%(2*Mod-2)/2))%=Mod;
    return 0*printf("%I64d\n",res);
}