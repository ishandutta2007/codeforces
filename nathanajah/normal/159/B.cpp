#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct x
{
    int c,d;
};
int n,m;
vector <x> awaln,awalm,akhirn,akhirm;
bool sudahn[200000];
bool sudahm[200000];
int i,j;
int n2,m2;
int t1,t2;
int beau,banyak;
x tmp;

bool cmp(x a, x b)
{
    if (a.d==b.d)
        return a.c<b.c;
    else
        return a.d<b.d;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&t1,&t2);
        tmp.c=t1;
        tmp.d=t2;
        awaln.push_back(tmp);
    }    
    for (i=0;i<m;i++)
    {
        scanf("%d %d",&t1,&t2);
        tmp.c=t1;
        tmp.d=t2;
        awalm.push_back(tmp);
    }
    sort(awalm.begin(),awalm.end(),cmp);
    sort(awaln.begin(),awaln.end(),cmp);
    i=0;j=0;
    while (i<n && j<m)
    {
        if (awaln[i].c ==awalm[j].c && awaln[i].d==awalm[j].d)
        {
            ++beau;
            sudahn[i]=true;
            sudahm[j]=true;
            ++i;
            ++j;
        }
        else if (cmp(awaln[i],awalm[j]))
            ++i;
        else
            ++j;
    }
    for (i=0;i<n;i++)
        if (!sudahn[i])
            akhirn.push_back(awaln[i]);
    for (i=0;i<m;i++)
        if (!sudahm[i])
            akhirm.push_back(awalm[i]);
    i=0;j=0;
    n2=akhirn.size();
    m2=akhirm.size();
    while (i<n2 && j<m2)
    {
        if (akhirn[i].d==akhirm[j].d)
        {
            ++banyak;
            ++i;++j;
        }
        else if (akhirn[i].d<akhirm[j].d)
            ++i;
        else
            ++j;
    }
    printf("%d %d\n",beau+banyak,beau);
}