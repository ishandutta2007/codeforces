#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n, m;

int n1;

int x, y;

char co;

int wyn;

int wcz;

int xx[1000007];
int yy[1000007];
char coco[1000007];

int l;
map <int,int> mapax;
map <int,int> mapay;

int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    {
        if (i>=v)
        {
            return i;
        }
    }
}

int drzewopio[2100000];
int drzewopoz[2100000];

int bylo[1000007];

void piszpoz(int v, int a, int b, int graa, int grab, int war)
{
    if (a>=graa && b<=grab)
    {
        drzewopoz[v]=max(drzewopoz[v], war);
        return;
    }
    if (a>grab || b<graa)
    {
        return;
    }
    piszpoz((v<<1), a, (a+b)>>1, graa, grab, war);
    piszpoz((v<<1)+1, (a+b+2)>>1, b, graa, grab, war);
}

int czytpoz(int v)
{
    int ret=0;
    v+=n1-1;
    while(v)
    {
        ret=max(ret, drzewopoz[v]);
        v>>=1;
    }
    return ret;
}

void piszpio(int v, int a, int b, int graa, int grab, int war)
{
    if (a>=graa && b<=grab)
    {
        drzewopio[v]=max(drzewopio[v], war);
        return;
    }
    if (a>grab || b<graa)
    {
        return;
    }
    piszpio((v<<1), a, (a+b)>>1, graa, grab, war);
    piszpio((v<<1)+1, (a+b+2)>>1, b, graa, grab, war);
}

int czytpio(int v)
{
    int ret=0;
    v+=n1-1;
    while(v)
    {
        ret=max(ret, drzewopio[v]);
        v>>=1;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    n1=potenga(m*4+5);
    //for (int i=1; i<2*n1; i++)
    //{
    //    drzewopio[i]=n+1;
    //}
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%s", &xx[i], &yy[i], &coco[i]);
        mapax[xx[i]]=0;
        mapay[yy[i]]=0;
    }
    mapax[0]=0;
    mapay[0]=0;
    mapax[n+1]=0;
    mapay[n+1]=0;
    l=0;
    for (map <int,int>::iterator it=mapax.begin(); it!=mapax.end(); it++)
    {
        l++;
        mapax[it->first]=l;
    }
    l=0;
    for (map <int,int>::iterator it=mapay.begin(); it!=mapay.end(); it++)
    {
        l++;
        mapay[it->first]=l;
    }
    for (int i=1; i<=m; i++)
    {
        x=xx[i];
        y=yy[i];
        co=coco[i];
        //printf("%d %d\n", mapax[x], mapay[y]);
        if (bylo[mapax[x]]==1)
        {
            printf("0\n");
            continue;
        }
        if (co=='L')
        {
            //printf("ras\n");
            wcz=czytpoz(mapax[x]);
            //printf(" %d\n", wcz);
            wyn=x-wcz;
            piszpio(1, 1, n1, mapay[y], mapay[y+wyn], y);
            printf("%d\n", wyn);
            bylo[mapax[x]]=1;
        }
        else
        {
            //printf("dwa\n");
            wcz=czytpio(mapay[y]);
            //printf(" %d\n", wcz);
            wyn=y-wcz;
            piszpoz(1, 1, n1, mapax[x], mapax[x+wyn], x);
            printf("%d\n", wyn);
            bylo[mapax[x]]=1;
        }
    }
    return 0;
}