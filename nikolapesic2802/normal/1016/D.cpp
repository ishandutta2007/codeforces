#include <bits/stdc++.h>

using namespace std;
int matrica[101][101];
int main()
{
    int n,m,a,b;
    scanf("%i %i",&n,&m);
    int x=0,xor1=0,xor2=0;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&a);
        if(i<n-1)
        {
            x^=a;
        }
        matrica[i][m-1]=a;
    }
    xor1=x;
    for(int i=0;i<m;i++)
    {
        scanf("%i",&b);
        if(i==m-1)
        {
            x^=b;
        }
        else
        {
            xor2^=b;
        }
        matrica[n-1][i]=b;
    }
    matrica[n-1][m-1]=x;
    //printf("%i %i %i\n",x,xor1,xor2);
    xor1^=x;
    xor2^=x;
    if(xor1==b&&xor2==a)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printf("%i ",matrica[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}