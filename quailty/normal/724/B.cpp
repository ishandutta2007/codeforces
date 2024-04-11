#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=25;
int a[MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int l=1;l<=m;l++)
        for(int r=l;r<=m;r++)
        {
            for(int i=1;i<=n;i++)
                swap(a[i][l],a[i][r]);
            int isok=1;
            for(int i=1;i<=n;i++)
            {
                int cnt=0;
                for(int j=1;j<=m;j++)
                    cnt+=(a[i][j]!=j);
                isok&=(cnt<=2);
            }
            if(isok)return 0*printf("YES");
            for(int i=1;i<=n;i++)
                swap(a[i][l],a[i][r]);
        }
    return 0*printf("NO");
}