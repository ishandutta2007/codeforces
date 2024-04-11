#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

int suka[400][400];
int posis[400][400];
int al[400];
int sekarang[400];
int posia[400];
int n,i,j;
int cansend;
int sendt;

int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        posis[i][0]=2000000000;
        for (j=1;j<=n;j++)
        {
            scanf("%d",&suka[i][j]);
            posis[i][suka[i][j]]=j;
        }
    }
    for (i=1;i<=n;i++)
    {
        scanf("%d",&al[i]);
        posia[al[i]]=i;
    }
    posia[0]=2000000000;
    for (i=1;i<=n;i++)
    {
        if (posia[i]<posia[cansend])
        {
            sendt=cansend;
            cansend=i;
        }
        else if (posia[i]<posia[sendt])
            sendt=i;
        for (j=1;j<=n;j++)
        {
            if (cansend==j)
            {
                if (posis[j][sekarang[j]]>posis[j][sendt])
                    sekarang[j]=sendt;
            }
            else
            if (posis[j][sekarang[j]]>posis[j][cansend] )
                sekarang[j]=cansend;
        }
    }
    for (i=1;i<=n;i++)
    {
        if (i>1)
            printf(" ");
        printf("%d",sekarang[i]);
    }
    printf("\n");
}