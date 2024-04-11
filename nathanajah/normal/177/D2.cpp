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

int n,m,c;
int a[200000];
int b[200000];
int i;
int tambah;

int main()
{
    scanf("%d %d %d",&n,&m,&c);
    for (i=0;i<n;++i)
        scanf("%d",&a[i]);
    for (i=0;i<m;++i)
        scanf("%d",&b[i]);
    for (i=0;i<n;++i)
    {
        if (i<m)
            tambah+=b[i];
        if (n-i<m)
            tambah-=b[i-(n-m+1)];
        a[i]=(a[i]+tambah)%c;
    }
    for (i=0;i<n;++i)
    {
        if (i>0)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}