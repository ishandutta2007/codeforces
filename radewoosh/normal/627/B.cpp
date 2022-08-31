#include <bits/stdc++.h>
using namespace std;

int n, k;

long long a, b;

int q;

long long tab[1000007];

long long sum[1000007];
long long wiea[1000007];
long long wieb[1000007];

int typ;
int p1, p2;

void pisz1(int v, long long w)
{
    for (int i=v; i<=n; i+=(-i&i))
    sum[i]+=w;
}

void pisz2(int v, long long w)
{
    for (int i=v; i<=n; i+=(-i&i))
    wiea[i]+=w;
}

void pisz3(int v, long long w)
{
    for (int i=v; i<=n; i+=(-i&i))
    wieb[i]+=w;
}

long long czyt1(int v, int u)
{
    long long ret=0;
    for (int i=u; i; i-=(-i&i))
    ret+=sum[i];
    for (int i=v-1; i; i-=(-i&i))
    ret-=sum[i];
    return ret;
}

long long czyt2(int v, int u)
{
    long long ret=0;
    for (int i=u; i; i-=(-i&i))
    ret+=wiea[i];
    for (int i=v-1; i; i-=(-i&i))
    ret-=wiea[i];
    return ret;
}

long long czyt3(int v, int u)
{
    long long ret=0;
    for (int i=u; i; i-=(-i&i))
    ret+=wieb[i];
    for (int i=v-1; i; i-=(-i&i))
    ret-=wieb[i];
    return ret;
}

int main()
{
    scanf("%d%d%lld%lld%d", &n, &k, &a, &b, &q);
    while(q--)
    {
        scanf("%d", &typ);
        if (typ==1)
        {
            scanf("%d%d", &p1, &p2);
            pisz1(p1, p2);
            if (tab[p1]<a && tab[p1]+p2>a)
            {
                pisz2(p1, tab[p1]+p2-a);
            }
            if (tab[p1]>=a)
            {
                pisz2(p1, p2);
            }
            if (tab[p1]<b && tab[p1]+p2>b)
            {
                pisz3(p1, tab[p1]+p2-b);
            }
            if (tab[p1]>=b)
            {
                pisz3(p1, p2);
            }
            tab[p1]+=p2;
        }
        else
        {
            scanf("%d", &p1);
            printf("%lld\n", czyt1(1, p1-1)+czyt1(p1+k, n)-czyt3(1, p1-1)-czyt2(p1+k, n));
        }
    }
    return 0;
}