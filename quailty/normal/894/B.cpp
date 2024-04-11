#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
int main()
{
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k==-1 && n%2!=m%2)return 0*printf("0\n");
    else printf("%lld\n",fp(fp(2,n-1),m-1));
    return 0;
}