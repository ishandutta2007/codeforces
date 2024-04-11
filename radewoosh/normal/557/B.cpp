#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long w;

long long tab[1000007];

long long dz, ch;

double wyn;

int main()
{
    scanf("%d%lld", &n, &w);
    for (int i=1; i<=2*n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    sort(tab+1, tab+1+2*n);
    dz=tab[1];
    ch=tab[n+1];
    wyn=min((double )dz, ((double) ch)/2);
    wyn=min((double) w, (wyn*3*n));
    printf("%.8lf", wyn);
    return 0;
}