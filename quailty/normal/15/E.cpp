#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
const ll Mod=1000000009;
int main()
{
    int n;
    scanf("%d",&n);
    if(n==2)return 0*printf("10");
    ll res=6,now=1,tmp=0,cur=4;
    for(int i=6;i<=n;i+=2)
    {
        tmp=(tmp+cur)%Mod;
        cur=2*cur%Mod;
        now=now*(tmp+1)%Mod;
        res=(res+4*now)%Mod;
    }
    res=res*res%Mod;
    res=2*(res+1)%Mod;
    return 0*printf("%lld",res);
}