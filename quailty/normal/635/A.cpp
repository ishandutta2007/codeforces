#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int t[15][15];
int main()
{
    int r,c,n,m;
    scanf("%d%d%d%d",&r,&c,&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        t[x][y]=1;
    }
    int res=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            for(int k=i;k<=r;k++)
                for(int l=j;l<=c;l++)
                {
                    int tot=0;
                    for(int p=i;p<=k;p++)
                        for(int q=j;q<=l;q++)
                            tot+=t[p][q];
                    if(tot>=m)res++;
                }
    printf("%d",res);
    return 0;
}