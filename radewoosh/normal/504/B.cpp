#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int n, m;

int potenga(int v)
{
    for (int i=1; 1; i*=2)
    if (i>=v)
    return i;
}

int p[200007];
int q[200007];

int kol[200007];

int drzewoq[1500000];
int drzewop[1500000];

int czytp(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
                return drzewop[v];
    }
    if (a>grab || b<graa)
    {
               return 0;
    }
    return czytp(v*2, a, (a+b)/2, graa, grab)+czytp(v*2+1, (a+b)/2+1, b, graa, grab);
}

int czytq(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
                return drzewoq[v];
    }
    if (a>grab || b<graa)
    {
               return 0;
    }
    return czytq(v*2, a, (a+b)/2, graa, grab)+czytq(v*2+1, (a+b)/2+1, b, graa, grab);
}

void zmiep(int v, int ile)
{
     v+=m;
     while(v)
     {
             drzewop[v]+=ile;
             v/=2;
     }
}

void zmieq(int v, int ile)
{
     v+=m;
     while(v)
     {
             drzewoq[v]+=ile;
             v/=2;
     }
}

int szup(int v, int a, int b, int num)
{
    //printf("%d %d %d   %d\n", v, a, b, num);
    if (a==b)
    {
             return a;
    }
    if (drzewop[v*2]<=num)
    return szup(v*2+1, (a+b)/2+1, b, num-drzewop[v*2]);
    return szup(v*2, a, (a+b)/2, num);
}

int u;

int main()
{
    scanf("%d", &n);
    m=potenga(n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &p[i]);
        zmiep(i-1, 1);
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &q[i]);
        zmieq(i-1, 1);
    }
    //printf("%d %d\n\n", czyt(1, 1, m, ));
    for (int i=1; i<=n; i++)
    {
        kol[i]=czytp(1, 0, m-1, 0, p[i])+czytq(1, 0, m-1, 0, q[i])-2;
        zmiep(p[i], -1);
        zmieq(q[i], -1);
        //printf("%d ", kol[i]);
    }
    //printf("\n");
    for (int i=n; i; i--)
    {
        kol[i-1]+=kol[i]/(n-i+1);
        kol[i]%=(n-i+1);
        //printf("%d ", kol[i]);
    }
    for (int i=0; i<n; i++)
    {
        zmiep(i, 1);
    }
    for (int i=1; i<=n; i++)
    {
        u=szup(1, 0, m-1, kol[i]);
        //printf("\n");
        zmiep(u, -1);
        printf("%d ", u);
    }
    return 0;
}