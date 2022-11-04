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
    int n,k;
    scanf("%d%d",&n,&k);
    ll now=1;
    for(int i=1;i<=n;i++)
    {
        ll c;
        scanf("%I64d",&c);
        now=lcm(now,c)%k;
    }
    return 0*printf("%s",(now==0 ? "Yes" : "No"));
}