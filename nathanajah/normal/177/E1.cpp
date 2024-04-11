#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int n,c,i;
int a[2000];
int sum;
int b[2000];
int banyak;

int hitung(long long x)
{
    int ret=0;
    int i;
    for (i=0;i<n;++i)
    {
        ret+=(x*a[i])/b[i];
        if (ret>c)
            return c+1;
    }
    return ret;
}
int main()
{
    scanf("%d %d",&n,&c);
    for (i=0;i<n;++i)
    {
        scanf("%d %d",&a[i],&b[i]);
        sum+=a[i];
    }
    c-=n;
    for (i=1;i<=30000;++i)
        if (hitung(i)==c)
            ++banyak;
    printf("%d\n",banyak);
}