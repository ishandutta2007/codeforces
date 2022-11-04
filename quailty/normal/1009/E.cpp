#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=998244353;
int a[MAXN],pw[MAXN];
int main()
{
    for(int i=(pw[0]=1);i<MAXN;i++)
        pw[i]=2*pw[i-1]%Mod;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i]=(a[i]+a[i-1])%Mod;
    int res=a[n];
    for(int i=1;i<=n-1;i++)
    {
        if(i<n-1)res=(res+1LL*(n-i-1)*pw[n-i-2]%Mod*a[i])%Mod;
        res=(res+2LL*pw[n-i-1]*a[i])%Mod;
    }
    printf("%d\n",res);
    return 0;
}