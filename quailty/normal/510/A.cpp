#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=m;j++)
            {
                printf("#");
            }
            printf("\n");
        }
        else
        {
            if(i%4)
            {
                for(int j=1;j<=m;j++)
                {
                    if(j==m)printf("#");
                    else printf(".");
                }
                printf("\n");
            }
            else
            {
                for(int j=1;j<=m;j++)
                {
                    if(j==1)printf("#");
                    else printf(".");
                }
                printf("\n");
            }
        }
    }
    return 0;
}