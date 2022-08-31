#include <bits/stdc++.h>
using namespace std;

int n, k;

long long tab2[1000007];
long long tab1[1000007];

int bsa, bsb, bss;

long long wyny[1000007];

double pr;

double wyn;

int rmqmin[23][1000007];
int rmqmax[23][1000007];

int naj[1000007];

long long wynik(int pocz, int kon)
{
    int s=naj[kon-pocz+1];
    return min(max(rmqmax[s][pocz], rmqmax[s][kon-(1<<s)+1]), min(rmqmin[s][pocz], rmqmin[s][kon-(1<<s)+1]));
}

int czy(int pocz, int kon)
{
    int s=naj[kon-pocz+1];
    return max(rmqmax[s][pocz], rmqmax[s][kon-(1<<s)+1])<min(rmqmin[s][pocz], rmqmin[s][kon-(1<<s)+1]);
}

int main()
{
    scanf("%d%d", &n, &k);
    naj[0]=0;
    for (int i=1; i<=n; i++)
    {
        naj[i]=naj[i-1];
        if (((1<<naj[i])*2)<=i)
        naj[i]++;
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab1[i]);
        tab1[i]*=100;
        rmqmax[0][i]=tab1[i];
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab2[i]);
        rmqmin[0][i]=tab2[i];
    }
    for (int h=0; h<=naj[n]; h++)
    {
        for (int i=1; i<=n; i++)
        {
            rmqmin[h+1][i]=min(rmqmin[h][i], rmqmin[h][i+(1<<h)]);
            rmqmax[h+1][i]=max(rmqmax[h][i], rmqmax[h][i+(1<<h)]);
        }
    }
    for (int i=1; i<=n; i++)
    {
        bsa=i;
        bsb=n;
        while(bsa<bsb)
        {
            bss=(bsa+bsb+2)>>1;
            if (!czy(i, bss))
            bsb=bss-1;
            else
            bsa=bss;
        }
        for (int j=max(i, bsa-2); j<=min(n, bsa+2); j++)
        wyny[i]=max(wyny[i], wynik(i, j));
    }
    sort(wyny+1, wyny+1+n);
    pr=(double)k/n;
    for (int i=1; i+k-1<=n; i++)
    {
        wyn+=pr*wyny[i];
        pr*=(double)(n-k-i+1);
        if (i!=n)
        pr/=(double)(n-i);
    }
    printf("%.9lf\n", wyn);
    return 0;
}