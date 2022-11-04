#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=1000000007;
int a[MAXN],inv[MAXN];
int main()
{
    for(int i=(inv[1]=1)+1;i<MAXN;i++)
        inv[i]=1LL*(Mod-Mod/i)*inv[Mod%i]%Mod;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int res=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n && a[i]==a[j])j++;
        if(j<=n)res=(res+1LL*(j-i)*inv[n+1-i]%Mod*a[i])%Mod;
    }
    for(int i=1;i<=n;i++)
        res=1LL*res*i%Mod;
    printf("%d\n",res);
    return 0;
}