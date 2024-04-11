#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

struct lol
{
    long long p,ind;
};
long long n,k;
long long duit;
long long i;
long long biaya[200000];
lol sbiaya[200000];
long long jumlah;
bool masuk[200000];

bool cmp(lol a, lol b)
{
    return a.p>b.p;
}
int main()
{
    scanf("%I64d %I64d",&n,&k);
    scanf("%I64d",&duit);
    for (i=0;i<n;++i)
    {
        scanf("%I64d",&biaya[i]);
        sbiaya[i].p=biaya[i];
        sbiaya[i].ind=i;
    }
    sort(sbiaya,sbiaya+n-1,cmp);
    for (i=0;i<k;++i)
    {
        jumlah+=sbiaya[i].p;
        masuk[sbiaya[i].ind]=true;
    }
    for (i=0;i<n-1;++i)
    {
        if (masuk[i])
        {
            if (jumlah>duit)
                break;
        }
        else
        {
            if (jumlah-sbiaya[k-1].p+biaya[i]>duit)
                break;
        }
    }
    printf("%I64d\n",i+1);
}