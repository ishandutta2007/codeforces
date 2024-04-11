#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=305;
int p[MAXN][MAXN],mx[MAXN],res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&p[i][j]);
    for(int i=1;i<=n;i++)
        mx[i]=n+1;
    for(int _=1;_<=n;_++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(p[n+1][j]!=i && p[n+1][j]<=_)
                {
                    int t=p[n+1][j];
                    for(int k=1;k<=n;k++)
                        if(p[i][k]==t)
                        {
                            if(mx[i]>k)
                            {
                                mx[i]=k;
                                res[i]=_;
                            }
                            break;
                        }
                    break;
                }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}