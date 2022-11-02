#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int i,j;
int a[300000];
int b[300000];
int balik[300000];
int res;

int main()
{
    scanf("%d",&n);
    for (i=0;i<n;++i)
        scanf("%d",&a[i]);
    for (i=0;i<n;++i)
    {
        scanf("%d",&b[i]);
        balik[b[i]]=i;
    }
    i=1;
    while (balik[a[i]]>balik[a[i-1]])
    {
        ++i;
        if (i==n)
            break;
    }
    printf("%d\n",n-i);
}