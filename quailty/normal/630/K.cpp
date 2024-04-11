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
    ll n;
    scanf("%I64d",&n);
    ll res=0;
    for(int i=0;i<(1<<9);i++)
    {
        int cnt=0,lcm=1;
        for(int j=0;j<9;j++)
            if(i&(1<<j))
            {
                cnt++;
                lcm=lcm/gcd(lcm,j+2)*(j+2);
            }
        if(cnt&1)res-=n/lcm;
        else res+=n/lcm;
    }
    printf("%I64d\n",res);
    return 0;
}