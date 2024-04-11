#include <cstdio>
using namespace std;

long long m;

long long h1, h2;
long long a1, a2;

long long x1, x2;
long long y1, y2;

int bylo[1000007];

long long ile;
long long dlu;

long long x3=1, y3=0;


int main()
{
    scanf("%lld", &m);
    scanf("%lld%lld", &h1, &a1);
    scanf("%lld%lld", &x1, &y1);
    scanf("%lld%lld", &h2, &a2);
    scanf("%lld%lld", &x2, &y2);
    while(h1!=a1)
    {
        if (bylo[h1])
        {
            printf("-1");
            return 0;
        }
        bylo[h1]=1;
        h1=(x1*h1+y1)%m;
        h2=(x2*h2+y2)%m;
        ile++;
    }
    for (int i=0; i<=m; i++)
    {
        bylo[i]=0;
    }
    if (h2==a2)
    {
        printf("%lld", ile);
        return 0;
    }
    while(!dlu || h1!=a1)
    {
        if (bylo[h1])
        {
            printf("-1");
            return 0;
        }
        bylo[h1]=1;
        dlu++;
        h1=(x1*h1+y1)%m;

        x3*=x2;
        y3*=x2;
        y3+=y2;
        x3%=m;
        y3%=m;
    }
    for (int i=0; i<=m; i++)
    {
        bylo[i]=0;
    }
    while(h2!=a2)
    {
        if (bylo[h2])
        {
            printf("-1");
            return 0;
        }
        bylo[h2]=1;
        h2=(x3*h2+y3)%m;
        ile+=dlu;
    }
    printf("%lld", ile);
    return 0;
}