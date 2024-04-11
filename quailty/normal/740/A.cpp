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
    ll n,a,b,c,res=(1LL<<60)-1;
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    for(int i=0;i<4;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<4;k++)
                if((n+i+2*j+3*k)%4==0)
                    res=min(res,a*i+b*j+c*k);
    printf("%I64d\n",res);
    return 0;
}