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
    ll n,a,b,p,q;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&p,&q);
    printf("%I64d",n/a*p+n/b*q-n/lcm(a,b)*min(p,q));
    return 0;
}