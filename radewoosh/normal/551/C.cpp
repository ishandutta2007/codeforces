#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

long long tab[100007];

long long taba[100007];

long long s;

int ost;

long long bsa, bsb, bss;

int pam;

long long zap;

long long x;

int check()
{
    for (int i=1; i<=n; i++)
    {
        taba[i]=tab[i];
    }
    pam=1;
    for (int i=1; i<=m; i++)
    {
        zap=bss-pam;
        while(zap>0)
        {
            if (pam>n)
            {
                return 1;
            }
            if (!taba[pam])
            {
                pam++;
                zap--;
                continue;
            }
            x=min(taba[pam], zap);
            taba[pam]-=x;
            zap-=x;
        }
    }
    if (taba[ost]>0)
    return 0;
    return 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        s+=tab[i];
        if (tab[i])
        ost=i;
    }
    bsa=1;
    bsb=100000000;
    bsb*=(bsb+1);
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        if (check())
        {
            bsb=bss;
        }
        else
        {
            bsa=bss+1;
        }
    }
    printf("%lld", bsa);
    return 0;
}