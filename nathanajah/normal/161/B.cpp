#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <bitset>
using namespace std;


long long n,k;

long long x[200000];
vector <long long> stool;
long long stsz;
long long pcsz;
vector <long long> pencil;
vector <long long> kart[2000];
long long i,j;
long long t1,t2;
bool ada[2000];
long long minstool;
long long jumlah;

bool cmp(long long a, long long b)
{
    return x[a]>x[b];
}

long long carimin(long long a)
{
    long long i;
    long long ret=2000000000000000LL;
    for (i=0;i<kart[a].size();i++)
        ret=min(ret,x[kart[a][i]]);
    return ret;
}
int main()
{
    scanf("%I64d %I64d",&n,&k);
    for (i=0;i<n;i++)
    {
        scanf("%I64d %I64d",&x[i],&t2);
        if (t2==1)
            stool.push_back(i);
        else
            pencil.push_back(i);
    }
    stsz=stool.size();
    pcsz=pencil.size();
    sort(stool.begin(),stool.end(),cmp);
    for (i=0;i<min(stsz,k);i++)
    {
        kart[i].push_back(stool[i]);
        ada[i]=true;
    }
    minstool=k-1;
    if (stsz>k)
    {
        for (i=k;i<stsz;i++)
            kart[minstool].push_back(stool[i]);
        for (i=0;i<pcsz;i++)
            kart[minstool].push_back(pencil[i]);
    }
    else
    {
        for (i=stsz;i<k;i++)
            kart[i].push_back(pencil[i-stsz]);
        for (i=k-stsz;i<pcsz;i++)
            kart[minstool].push_back(pencil[i]);
    }
    for (i=0;i<k;i++)
    {
        for (j=0;j<kart[i].size();j++)
            jumlah+=2*x[kart[i][j]];
        if (ada[i])
            jumlah-=carimin(i);
    }
    printf("%.1lf\n",(double)jumlah/2.0);
    for (i=0;i<k;i++)
    {
        printf("%d ",kart[i].size());
        printf("%I64d",kart[i][0]+1);
        for (j=1;j<kart[i].size();j++)
            printf(" %I64d",kart[i][j]+1);
        printf("\n");
    }
    
    
}