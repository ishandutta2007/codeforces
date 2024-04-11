#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll lcm(int a,int b,int c)
{
    //printf("%i %i %i\n",a,b,c);
    ll x =(ll)a*(ll)b/(ll)gcd(a,b);
    ll res=(ll)c*x/(ll)gcd(c,x);
    //printf("%lld  %i %lld\n",x/x1,x1,x);
    return res;

}
int main()
{
    int n;
    scanf("%i",&n);
    ll maxx=1;
    for(int i=n; i>max(0,n-75); i--)
    {
        for(int i2=n; i2>max(0,n-75); i2--)
        {
            for(int i3=n; i3>max(0,n-75); i3--)
            {
                maxx=max(maxx,lcm(i,i2,i3));
            }
        }
    }
    printf("%lld\n",maxx);
    return 0;
}