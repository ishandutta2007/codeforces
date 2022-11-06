#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a;
        a=a*a;
        k>>=1;
    }
    return res;
}
int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    int t=r-l+1;
    if(n==1)return 0*printf("%d",t);
    if(n==2)return 0*printf("%lld",1LL*t*(t-1));
    if(n>30)return 0*printf("0");
    ll res=0;
    for(int q=1;;q++)
    {
        ll tq=fp(q,n-1);
        if(tq>r)break;
        for(int p=q+1;;p++)
        {
            ll tp=fp(p,n-1);
            if(tp>r)break;
            if(gcd(p,q)>1)continue;
            ll mi=(l+tq-1)/tq,mx=r/tp;
            res+=max(0LL,mx-mi+1);
        }
    }
    return 0*printf("%lld",res*2);
}