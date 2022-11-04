#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll p=1000000007;
char s[100005];
ll w[100005];
ll te[100005]={1};
void build()
{
    for(int i=1;i<=100000;i++)
    {
        te[i]=(te[i-1]*10)%p;
    }
}
ll quick_mod(ll a, ll b)
{
    ll ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

ll C(ll n, ll m)
{
    if(m > n) return 0;
    ll ans = 1;
    for(int i=1; i<=m; i++)
    {
        ll a = (n + i - m) % p;
        ll b = i % p;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
    }
    return ans;
}

int main()
{
    build();
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    scanf("%s",s);
    ll ans=0;
    w[n-1]=C(n-1,k);
    ll t=w[n-1];
    for(int i=n-1;i>=1;i--)
    {
        t=t*((i-k)*quick_mod(i,p-2)%p)%p;
        w[i-1]=(w[i]+(te[n-i-1]*t)%p*9)%p;
    }
    for(int i=0;i<n;i++)
        ans=(ans+w[i]*(s[i]-'0'))%p;
    printf("%I64d",ans);
    return 0;
}