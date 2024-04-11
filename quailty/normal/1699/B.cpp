#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
int a[MAXN][MAXN];
int solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n/2;i++)
        for(int j=1;j<=m/2;j++)
        {
            if((i+j)&1)
            {
                a[2*i-1][2*j-1]=0;
                a[2*i-1][2*j]=1;
                a[2*i][2*j-1]=1;
                a[2*i][2*j]=0;
            }
            else
            {
                a[2*i-1][2*j-1]=1;
                a[2*i-1][2*j]=0;
                a[2*i][2*j-1]=0;
                a[2*i][2*j]=1;
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            printf("%d%c",a[i][j]," \n"[j==m]);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}