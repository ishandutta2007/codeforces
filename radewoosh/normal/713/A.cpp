#include <bits/stdc++.h>
using namespace std;

int t;

char wcz[5];
long long x;

map <long long,long long> mapa;

long long prze(long long v)
{
    long long r=1;
    long long ret=0;
    while(v)
    {
        ret+=(v&1)*r;
        v/=10;
        r*=10;
    }
    return ret;
}


int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%lld", wcz, &x);
        if (wcz[0]=='+')
        {
            mapa[prze(x)]++;
        }
        if (wcz[0]=='-')
        {
            mapa[prze(x)]--;
        }
        if (wcz[0]=='?')
        {
            printf("%lld\n", mapa[prze(x)]);
        }
    }
    return 0;
}