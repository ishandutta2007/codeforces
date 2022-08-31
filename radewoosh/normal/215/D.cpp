#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long m;

long long t, lim, x, k;

long long wyn;

long long roz;
long long dziel;
long long resz;
long long moz1;
long long moz2;

int main()
{
    scanf("%d%lld", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld%lld", &t, &lim, &x, &k);
        if (lim<=t)
        {
            wyn+=m*x+k;
            continue;
        }
        roz=lim-t;
        if (m<=roz)
        {
            wyn+=k;
            continue;
        }
        dziel=(m+roz-1)/roz;
        moz1=dziel*k;

        dziel=(m/roz);
        resz=m%roz;
        moz2=k+resz*x+dziel*min(k, roz*x);
        wyn+=min(moz1, moz2);
    }
    printf("%lld", wyn);
    return 0;
}