#include <cstdio>
using namespace std;

long long n;

long long m=1;

long long wyn;

int licz=1;

int main()
{
    scanf("%lld", &n);
    while((m*10)<=n)
    {
        m*=10;
        licz++;
    }
    while(m)
    {
        wyn+=((n-m)+1)*licz;
        licz--;
        n=m-1;
        m/=10;
    }
    printf("%lld", wyn);
    return 0;
}