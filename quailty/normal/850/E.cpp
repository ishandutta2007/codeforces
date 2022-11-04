#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=(1<<20)+5;
const int Mod=1000000007;
char str[MAXN];
int f[MAXN];
int main()
{
    int n;
    scanf("%d%s",&n,str);
    for(int i=0;i<(1<<n);i++)
        f[i]=(str[i]-'0');
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)if(~j&(1<<i))
        {
            int u=f[j],v=f[j|(1<<i)],t=(u+v)%Mod;
            f[j]=(t+u)%Mod,f[j|(1<<i)]=(t+v)%Mod;
        }
    int res=0;
    for(int i=0;i<(1<<n);i++)
        if(str[i]=='1')res=(res+f[i])%Mod;
    res=3LL*res%Mod;
    printf("%d\n",res);
    return 0;
}