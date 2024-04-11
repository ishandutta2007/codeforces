#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300005;
const int Mod=1000000007;
int pw[MAXN],x[MAXN];
int main()
{
    for(int i=(pw[0]=1);i<MAXN;i++)
        pw[i]=2LL*pw[i-1]%Mod;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=(res-1LL*x[i]*pw[n-i])%Mod;
        res=(res+1LL*x[i]*pw[i-1])%Mod;
    }
    return 0*printf("%d",(res+Mod)%Mod);
}