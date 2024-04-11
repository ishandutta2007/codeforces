#include <bits/stdc++.h>
using namespace std;

long long n;
char b;

int dod[100007];

long long czt;

int main()
{
    dod['f']=1;
    dod['e']=2;
    dod['d']=3;
    dod['a']=4;
    dod['b']=5;
    dod['c']=6;
    scanf("%lld%c", &n, &b);
    n--;
    if (n&2)
        n^=2;
    czt=n/4;
    printf("%lld\n", czt*16+(n&1)*7+dod[b]);
    return 0;
}