#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n,i;
int a[20000];
int cnt[20000];
int banyak;

int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for (i=1;i<=n;i++)
        if (cnt[i]==0)
            banyak++;
    printf("%d\n",banyak);
}