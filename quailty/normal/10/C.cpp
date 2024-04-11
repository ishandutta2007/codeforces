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
    ll n,p[9];
    scanf("%I64d",&n);
    for(int i=1;i<=9;i++)
        p[i%9]=n/9+(i<=n%9);
    ll res=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            res+=p[i]*p[j]*p[i*j%9];
    for(int i=1;i<=n;i++)
        res-=n/i;
    printf("%I64d",res);
    return 0;
}