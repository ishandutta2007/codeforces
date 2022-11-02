#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int n;
int a[200];
int i;
int banyak,penalty;
int t=10;


int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    i=0;
    while (t<720 && i<n)
    {
        t+=a[i];
        if (t<=720)
        {
            banyak++;
            penalty+=max(0,t-360);
        }
        i++;
    }
    printf("%d %d\n",banyak,penalty);
}