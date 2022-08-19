#include <bits/stdc++.h>
using namespace std;

int q;

int typ;
long long a, b, w;

map <long long,long long> mapa;

int main()
{
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &typ);
        if (typ==1)
        {
            scanf("%lld%lld%lld", &a, &b, &w);
            while(a!=b)
            {
                if (b>a)
                swap(a, b);
                mapa[a]+=w;
                a/=2;
            }
        }
        else
        {
            scanf("%lld%lld", &a, &b);
            w=0;
            while(a!=b)
            {
                if (b>a)
                swap(a, b);
                w+=mapa[a];
                a/=2;
            }
            printf("%lld\n", w);
        }
    }
    return 0;
}