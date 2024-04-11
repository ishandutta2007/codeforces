#include <bits/stdc++.h>
using namespace std;

int n;

long long x[1000007];
long long y[1000007];

int p1, p2, p3;

long long ilowek(int a, int b, int c)
{
    return (x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]);
}

int ok(int a, int b, int c)
{
    return (ilowek(a, b, c)!=0);
}

int mag(int a, int b, int c)
{
    long long p=ilowek(a, b, c);
    if (p>0)
    return 1;
    if (p<0)
    return -1;
    return 0;
}

int we(int a, int b, int c, int x)
{
    if (mag(a, b, x)==mag(a, c, x))
    return 0;
    if (mag(b, a, x)==mag(b, c, x))
    return 0;
    if (mag(c, a, x)==mag(c, b, x))
    return 0;
    return 1;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    p1=1;
    p2=2;
    for (int i=3; i<=n; i++)
    {
        if (ok(1, 2, i))
        {
            p3=i;
            break;
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (i==p1 || i==p2 || i==p3)
        continue;
        if (ok(p1, p2, p3) && !we(p1, p2, p3, i))
        {
            continue;
        }
        if (ok(p1, p2, i) && !we(p1, p2, i, p3))
        {
            p3=i;
            continue;
        }
        if (ok(p1, i, p3) && !we(p1, i, p3, p2))
        {
            p2=i;
            continue;
        }
        if (ok(i, p2, p3) && !we(i, p2, p3, p1))
        {
            p1=i;
            continue;
        }
    }
    printf("%d %d %d\n", p1, p2, p3);
    return 0;
}