#include <bits/stdc++.h>
using namespace std;

int n;

int a1, b1, a2, b2;
int c1, d1, c2, d2;

int bsa, bsb, bss;

int odp;

int czyw(int a, int b, int c, int d)
{
    return (c1>=a && c2<=c && d1>=b && d2<=d);
}

int main()
{
    scanf("%d", &n);
    bsa=1;
    bsb=n;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        printf("? %d %d %d %d\n", 1, 1, bss, n);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp>=1)
            bsb=bss;
        else
            bsa=bss+1;
    }
    a2=bsa;

    bsa=1;
    bsb=a2;
    while(bsa<bsb)
    {
        bss=(bsa+bsb+2)>>1;
        printf("? %d %d %d %d\n", bss, 1, a2, n);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp>=1)
            bsa=bss;
        else
            bsb=bss-1;
    }
    a1=bsa;

    bsa=1;
    bsb=n;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        printf("? %d %d %d %d\n", a1, 1, a2, bss);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp>=1)
            bsb=bss;
        else
            bsa=bss+1;
    }
    b2=bsa;

    bsa=1;
    bsb=b2;
    while(bsa<bsb)
    {
        bss=(bsa+bsb+2)>>1;
        printf("? %d %d %d %d\n", a1, bss, a2, b2);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp>=1)
            bsa=bss;
        else
            bsb=bss-1;
    }
    b1=bsa;


    //
    //
    //
    c1=a1;
    c2=a2;
    d1=b1;
    d2=b2;
    //
    //
    //
    bsa=1;
    bsb=n;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        printf("? %d %d %d %d\n", 1, 1, bss, n);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp-czyw(1, 1, bss, n)>=1)
            bsb=bss;
        else
            bsa=bss+1;
    }
    a2=bsa;

    bsa=1;
    bsb=a2;
    while(bsa<bsb)
    {
        bss=(bsa+bsb+2)>>1;
        printf("? %d %d %d %d\n", bss, 1, a2, n);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp-czyw(bss, 1, a2, n)>=1)
            bsa=bss;
        else
            bsb=bss-1;
    }
    a1=bsa;

    bsa=1;
    bsb=n;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        printf("? %d %d %d %d\n", a1, 1, a2, bss);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp-czyw(a1, 1, a2, bss)>=1)
            bsb=bss;
        else
            bsa=bss+1;
    }
    b2=bsa;

    bsa=1;
    bsb=b2;
    while(bsa<bsb)
    {
        bss=(bsa+bsb+2)>>1;
        printf("? %d %d %d %d\n", a1, bss, a2, b2);
        fflush(stdout);
        scanf("%d", &odp);
        if (odp-czyw(a1, bss, a2, b2)>=1)
            bsa=bss;
        else
            bsb=bss-1;
    }
    b1=bsa;

    printf("! %d %d %d %d %d %d %d %d\n", a1, b1, a2, b2, c1, d1, c2, d2);

    return 0;
}