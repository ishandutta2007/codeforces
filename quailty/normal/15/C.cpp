#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cal(ll n)
{
    ll res=(n%4==1 || n%4==2);
    for(int i=2;i<60;i++)
    {
        ll t=n%(1LL<<i);
        if(t>=(1LL<<(i-1)) && t%2==0)
            res|=(1LL<<i);
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        ll x,m;
        scanf("%lld%lld",&x,&m);
        sum^=cal(x+m-1)^cal(x-1);
    }
    return 0*printf("%s",(sum ? "tolik" : "bolik"));
}