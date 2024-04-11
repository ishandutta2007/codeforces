#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int gcd(ll a,ll b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
bool test(ll a)
{
    for(ll i=2;i*i<=a;i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}
int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll x=(a-b),y=a+b;
        //printf("%lld %lld\n",x,y);
        if(x==1&&test(y))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}