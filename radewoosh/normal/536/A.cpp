#include <cstdio>
using namespace std;

long long a, b;

int n;

long long liczdo(int zas)
{
    return a*zas+(b*(zas-1)*zas)/2;
}

long long liczm(int lew, int pra)
{
    return liczdo(pra)-liczdo(lew-1);
}

int l;
long long m, t;

int bsa, bsb, bss;

int main()
{
    scanf("%lld%lld%d", &a, &b, &n);
    //printf("%lld\n\n", liczm(1, 4));
    while(n--)
    {
        scanf("%d%lld%lld", &l, &t, &m);
        if (t<a+(l-1)*b)
        {
            printf("-1\n");
            continue;
        }
        bsa=l;
        bsb=(t-a)/b+5;
        while(bsa<bsb)
        {
            bss=(bsa+bsb+2)>>1;
            //printf("%d    %lld\n", bss, liczm(l, bss));
            if (liczm(l, bss)<=t*m && liczm(bss, bss)<=t)
            {
                bsa=bss;
            }
            else
            {
                bsb=bss-1;
            }
        }
        printf("%d\n", bsa);
    }
    return 0;
}