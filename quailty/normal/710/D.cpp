#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll floor(ll n,ll k)
{
    return (n>0 ? n/k : (n-k+1)/k);
}
ll ceil(ll n,ll k)
{
    return (n>0 ? (n+k-1)/k : n/k);
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0 && b==0)return -1;
    if(b==0)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
int main()
{
    ll a[2],b[2],L,R;
    for(int i=0;i<2;i++)
        scanf("%I64d%I64d",&a[i],&b[i]);
    scanf("%I64d%I64d",&L,&R);
    L=max({L,b[0],b[1]});
    if(L>R)return 0*printf("0");
    ll x,y,g=exgcd(a[0],-a[1],x,y);
    if((b[1]-b[0])%g)return 0*printf("0");
    x=x*(b[1]-b[0])/g%(a[1]/g);
    ll s=a[0]*x+b[0],l=abs(a[0]*a[1]/g),t;
    t=ceil(L-s,l),L=s+l*t;
    t=floor(R-s,l),R=s+l*t;
    return 0*printf("%I64d",(R-L)/l+1);
}