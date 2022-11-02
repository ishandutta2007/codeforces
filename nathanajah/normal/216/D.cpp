#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#ifdef DEBUG
    #define debug(...) \
    fprintf(stderr,__VA_ARGS__)
#else
    #define debug(...) 
#endif
using namespace std;

int bitl[100005];
int bitr[100005];
vector <int> p[1005];
int n,k[1005];
int i,j;
int tmp;

void updl(int x, int y)
{
    while (x<=100005)
    {
        bitl[x]+=y;
        x+=(x&-x);
    }
}

void updr(int x, int y)
{
    while (x<=100005)
    {
        bitr[x]+=y;
        x+=(x&-x);
    }
}

int getl(int x)
{
    if (x<=0)
        return 0;
    int res=0;
    while (x>0)
    {
        res+=bitl[x];
        x-=(x&-x);
    }
    return res;
}

int getr(int x)
{
    if (x<=0)
        return 0;
    int res=0;
    while (x>0)
    {
        res+=bitr[x];
        x-=(x&-x);
    }
    return res;
}
int l,r;
int res;
int main()
{
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d",&k[i]);
        for (j=0;j<k[i];++j)
        {
            scanf("%d",&tmp);
            p[i].push_back(tmp);
        }
        sort(p[i].begin(),p[i].end());
    }
    for (i=0;i<n;++i)
    {
        l=(n+i-1)%n;
        r=(i+1)%n;
        for (j=0;j<k[l];++j)
            updl(p[l][j],1);
        for (j=0;j<k[r];++j)
            updr(p[r][j],1);
        for (j=0;j<k[i]-1;++j)
        {
            if (getl(p[i][j+1])-getl(p[i][j]-1)!=getr(p[i][j+1])-getr(p[i][j]-1))
            {
                ++res;
            }
        }
        for (j=0;j<k[l];++j)
            updl(p[l][j],-1);
        for (j=0;j<k[r];++j)
            updr(p[r][j],-1);
    }
    printf("%d\n",res);
}