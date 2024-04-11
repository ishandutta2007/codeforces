#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct fig
{
    long long k,c;
};
bool operator< (fig a, fig b)
{
    return a.c<b.c;
}
long long n,i;
fig daf[200];
long long t,p[200];
long long p1,p2;
long long total;
long long sudah;

int main()
{
    scanf("%I64d",&n);
    for (i=0;i<n;++i)
        scanf("%I64d %I64d",&daf[i].k,&daf[i].c);
    sort(daf,daf+n);
    scanf("%I64d",&t);
    for (i=0;i<t;++i)
        scanf("%I64d",&p[i]);
    p[t]=1000000000000000LL;
    p1=0;
    sudah=0;
    p2=0;
    while (p1<n)
    {
        if (sudah+daf[p1].k<=p[p2])
        {
            sudah+=daf[p1].k;
            total+=daf[p1].k*daf[p1].c*(p2+1);
            daf[p1].k=0;
            ++p1;
        }
        else
        {
            total+=((p[p2]-sudah)*(p2+1)*daf[p1].c);
            daf[p1].k-=p[p2]-sudah;
            sudah=p[p2];
            ++p2;
        }
    }
    printf("%I64d\n",total);
}