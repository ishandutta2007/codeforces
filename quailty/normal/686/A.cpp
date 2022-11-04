#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll n,x,d,t=0;
    scanf("%I64d%I64d",&n,&x);
    while(n--)
    {
        char s[5];
        scanf("%s%I64d",s,&d);
        if(*s=='+')x+=d;
        else
        {
            if(x>=d)x-=d;
            else t++;
        }
    }
    printf("%I64d %I64d\n",x,t);
    return 0;
}