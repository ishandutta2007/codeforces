#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    scanf("%i %i %i",&n,&a,&b);
    if(a!=1&&b!=1)
    {
        printf("NO\n");
        return 0;
    }
    if(n==1)
    {
        printf("YES\n0\n");
        return 0;
    }
    if(n==2||n==3)
    {
        if(a==1&&b==1)
        {
            printf("NO\n");
            return 0;
        }
    }
    int matrica[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrica[i][j]=0;
        }
    }
    int sta=max(a,b);
    for(int i=sta;i<n;i++)
    {
        matrica[i][i-1]=1;
        matrica[i-1][i]=1;
    }
    printf("YES\n");
    if(a==1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    printf("0");
                }
                else
                printf("%i",(matrica[i][j]+1)%2);
            }
            printf("\n");
        }
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%i",matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}