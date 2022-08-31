#include <cstdio>
#include <algorithm>
using namespace std;

int n;

long long tab[100007];
long long czas;
int wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        if (tab[i]>=czas)
        {
            czas+=tab[i];
            wyn++;
        }
    }
    printf("%d", wyn);
    return 0;
}