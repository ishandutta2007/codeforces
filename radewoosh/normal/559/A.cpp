#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

long long tab[10];

long long wyn;

int czy;

int sum;

int main()
{
    for (int i=1; i<=6; i++)
    {
        scanf("%lld", &tab[i]);
    }
    wyn-=tab[1]*tab[1];
    wyn-=tab[3]*tab[3];
    wyn-=tab[5]*tab[5];
    wyn+=(tab[1]+tab[2]+tab[3])*(tab[1]+tab[2]+tab[3]);
    printf("%lld", wyn);
    return 0;
}