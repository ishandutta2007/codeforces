#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    ll t,w,b;
    scanf("%I64d%I64d%I64d",&t,&w,&b);
    ll g=gcd(w,b),res=-1;
    if(t/w<b/g)res+=min(t+1,min(w,b));
    else res+=t/lcm(w,b)*min(w,b)+min(t%lcm(w,b)+1,min(w,b));
    printf("%I64d/%I64d",res/gcd(res,t),t/gcd(res,t));
    return 0;
}