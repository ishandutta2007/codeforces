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
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    ll t=1;
    for(int i=1;i<=10;i++)
        t=t/gcd(i,t)*i;
    ll n;
    scanf("%I64d",&n);
    printf("%I64d\n",n/t);
    return 0;
}