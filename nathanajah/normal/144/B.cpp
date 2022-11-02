#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int xa,xb,ya,yb;
int i,j;
int x[2000],y[2000],r[2000];
int n;
int banyak;
bool bisa;

int sqr(int x)
{
    return x*x;
}
bool cek (int xx, int yy, int n)
{
    if (sqr(xx-x[n])+sqr(yy-y[n])<=sqr(r[n]))
        return true;
    return false;
}
int main()
{
    scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d %d %d",&x[i],&y[i],&r[i]);
    for (i=min(xa,xb);i<=max(xa,xb);i++)
    {
        bisa=false;
        for (j=0;j<n;j++)
            if (cek(i,ya,j))
                bisa=true;
        if (!bisa)
            banyak++;
        bisa=false;
        for (j=0;j<n;j++)
            if (cek(i,yb,j))
                bisa=true;
        if (!bisa)
            banyak++;
            
    }
    for (i=min(ya,yb)+1;i<=max(ya,yb)-1;i++)
    {
        bisa=false;
        for (j=0;j<n;j++)
            if (cek(xa,i,j))
                bisa=true;
        if (!bisa)
            banyak++;
        bisa=false;
        for (j=0;j<n;j++)
            if (cek(xb,i,j))
                bisa=true;
        if (!bisa)
            banyak++;
    }
    printf("%d\n",banyak);
}