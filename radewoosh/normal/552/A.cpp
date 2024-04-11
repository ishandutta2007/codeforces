#include <cstdio>
using namespace std;

int n;

long long a, b, c, d;

long long wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        wyn+=(c-a+1)*(d-b+1);
    }
    printf("%lld", wyn);
    return 0;
}