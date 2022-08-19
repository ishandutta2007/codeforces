#include <cstdio>
using namespace std;

int n, m;

int lim;

int a;
long long mod;
long long dyn[507][507];
long long wyn;

int main()
{
    scanf("%d%d%d%lld", &n, &m, &lim, &mod);
    dyn[0][0]=1;
    for (int h=1; h<=n; h++)
    {
        scanf("%d", &a);
        for (int i=0; i<m; i++)
        {
            for (int j=0; j+a<=lim; j++)
            {
                dyn[i+1][j+a]+=dyn[i][j];
                dyn[i+1][j+a]%=mod;
            }
        }
    }
    for (int i=0; i<=lim; i++)
    {
        wyn+=dyn[m][i];
    }
    wyn%=mod;
    printf("%lld", wyn);
    return 0;
}