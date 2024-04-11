#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=4005;
const int Mod=1000000007;
int C[MAXN][MAXN],S[MAXN][MAXN],B[MAXN];
void build()
{
    C[0][0]=1;
    for(int i=1;i<=4000;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=4000;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    S[0][0]=1;
    for(int i=1;i<=4000;i++)
        for(int j=1;j<=4000;j++)
            S[i][j]=(S[i-1][j-1]+1LL*j*S[i-1][j]%Mod)%Mod;
    for(int i=0;i<=4000;i++)
        for(int j=0;j<=i;j++)
            B[i]=(B[i]+S[i][j])%Mod;
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
        ans=(ans+1LL*C[n][i]*B[i]%Mod)%Mod;
    printf("%d\n",ans);
    return 0;
}