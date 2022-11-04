#include<bits/stdc++.h>
using namespace std;
const int MAXN=1055;
const int MAXM=25;
const int Mod=1000000007;
int C[MAXN][MAXM];
int main()
{
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXM;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",C[2*m+n-1][2*m]);
    return 0;
}