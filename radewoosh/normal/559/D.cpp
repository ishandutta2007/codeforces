#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long m;
pair <long long,long long> tab[1000007];

long double pot[107];
long double pol;
long double kra;
int k;

double wyn;

long double licz, mian, szan;

long long ilo(pair <long long,long long> a, pair <long long,long long> b)
{
    return (a.first*b.second)-(a.second*b.first);
}

long long g, d;

int main()
{
    scanf("%d", &n);
    m=n;
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &tab[i].first, &tab[i].second);
        tab[n+i]=tab[i];
    }
    pot[0]=1;
    for (int i=1; i<=100; i++)
    {
        pot[i]=pot[i-1]*2;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=min(55, n-2); j++)
        {
            if (n<=55)
            {
                licz=pot[n-j-1]-1;
                mian=pot[n]-1-m-m*(m-1)/2;
                szan=licz/mian;
            }
            else
            {
                licz=1;
                mian=pot[j+1];
                szan=licz/mian;
            }
            k=i+j;
            if (k>n)
            k-=n;

            g=tab[i].first-tab[k].first;
            g=max(g, -g);
            d=tab[i].second-tab[k].second;
            d=max(d, -d);

            //printf("%d %d   %Lf\n", i, k, szan);
            //printf("%lld %lld\n", __gcd(g, d), ilo(tab[i], tab[k]));

            kra+=__gcd(g, d)*szan;
            pol+=ilo(tab[i], tab[k])*szan/2;
        }
    }
    pol=max(pol, -pol);
    wyn=pol-(kra/2)+1;
    printf("%.10lf", wyn);
    return 0;
}