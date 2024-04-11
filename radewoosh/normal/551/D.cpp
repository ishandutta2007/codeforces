#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, l, m;

long long wyn=1;

int ilej, ilez;

long long razj, razz;

long long mac[5][5];
long long macp[5][5];

long long wek[5];
long long wekp[5];

long long x=2;
long long ret=1;

int main()
{
    scanf("%lld%lld%lld%lld", &n, &k, &l, &m);
    for (int i=0; i<l; i++)
    {
        if (k&1)
        ilej++;
        else
        ilez++;
        k>>=1;
    }
    if (k)
    {
        printf("0");
        return 0;
    }
    wek[1]=1;
    wek[2]=0;
    mac[1][1]=1;
    mac[1][2]=1;
    mac[2][1]=1;
    mac[2][2]=0;
    while(n)
    {
        if (n&1)
        {
            for (int i=1; i<=2; i++)
            {
                wekp[i]=wek[i];
                wek[i]=0;
            }
            for (int i=1; i<=2; i++)
            {
                for (int j=1; j<=2; j++)
                {
                    wek[i]+=mac[i][j]*wekp[j];
                    wek[i]%=m;
                }
            }
            ret*=x;
            ret%=m;
        }
        for (int i=1; i<=2; i++)
        {
            for (int j=1; j<=2; j++)
            {
                macp[i][j]=mac[i][j];
                mac[i][j]=0;
            }
        }
        for (int i=1; i<=2; i++)
        {
            for (int j=1; j<=2; j++)
            {
                for (int l=1; l<=2; l++)
                {
                    mac[i][j]+=macp[i][l]*macp[l][j];
                    mac[i][j]%=m;
                }
            }
        }
        x*=x;
        x%=m;
        n>>=1;
    }
    for (int i=1; i<=ilez; i++)
    {
        wyn*=(wek[1]+wek[2]);
        wyn%=m;
    }
    for (int i=1; i<=ilej; i++)
    {
        wyn*=(m+m+ret-(wek[1]+wek[2]));
        wyn%=m;
    }
    printf("%lld", wyn%m);
    return 0;
}