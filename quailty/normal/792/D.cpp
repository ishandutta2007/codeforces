#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[100005];
int main()
{
    ll n,q;
    scanf("%lld%lld",&n,&q);
    n=(n+1)>>1;
    while(q--)
    {
        ll u;
        scanf("%lld%s",&u,s);
        for(int i=0;s[i];i++)
        {
            if(s[i]=='L')
            {
                if((u&-u)>1)u-=(u&-u)>>1;
            }
            if(s[i]=='R')
            {
                if((u&-u)>1)u+=(u&-u)>>1;
            }
            if(s[i]=='U')
            {
                if((u&-u)<n)u+=(~u&((u&-u)<<1) ? u&-u : -(u&-u));
            }
        }
        printf("%lld\n",u);
    }
    return 0;
}