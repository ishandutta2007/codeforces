#include <bits/stdc++.h>
using namespace std;

int n, k, x;

long long tab[1000007];

long long najm=1000000000, najw=-1000000000;

double bsa;
double bsb;
double bss1, bss2;

double licz(double s)
{
    double zwr=0.0;
    double p=0.0;
    double mini=0.0;
    for (int i=1; i<=n; i++)
    {
        p+=tab[i]-s;
        if (p<mini)
        {
            mini=p;
        }
        zwr=max(zwr, abs(p-mini));
    }
    mini=0.0;
    p=0.0;
    for (int i=1; i<=n; i++)
    {
        p+=tab[i]-s;
        if (p>mini)
        {
            mini=p;
        }
        zwr=max(zwr, abs(p-mini));
    }
    return zwr;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        najm=min(najm, tab[i]);
        najw=max(najw, tab[i]);
    }
    bsb=(double) najw;
    bsa=(double) najm;
    for (int h=1; h<=200 && bsa<bsb; h++)
    {
        bss1=bsa+(((bsb-bsa)/9.0)*4.0);
        bss2=bsa+(((bsb-bsa)/9.0)*5.0);
        if (licz(bss1)<licz(bss2))
        {
            bsb=bss2;
        }
        else
        {
            bsa=bss1;
        }
    }
    printf("%.9lf\n", licz(bsa));
    return 0;
}