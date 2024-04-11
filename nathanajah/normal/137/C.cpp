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

struct ev
{
    int s,f;
};

ev hist[200000];
int i;
int n;
int lastf;
int maxf;
int banyak;

bool cmp(ev a, ev b)
{
    return a.s<b.s;
}

int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&hist[i].s,&hist[i].f);
    }
    sort(hist,hist+n,cmp);
    lastf=hist[0].f;
    for (i=1;i<n;i++)
    {
        if (hist[i].f<lastf)
        {
            banyak++;
        }
        else
            lastf=hist[i].f;
    }
    printf("%d\n",banyak);
}