#include <bits/stdc++.h>
using namespace std;

int n, m;

int tab[1007][1007];

int tu[1007][1007];

int najw[1007];

int t;
int a1[1000007];
int b1[1000007];
int a2[1000007];
int b2[1000007];

int wyn[1000007];

vector <int> wek[1007][1007];

int tak[1007];

inline int czyok(int v, int u, int d)
{
    if (v-d<0 || u-d<0)
        return 0;
    return (tab[v][u]-tab[v-d][u]-tab[v][u-d]+tab[v-d][u-d])==d*d;
}

inline void rob(int v)
{
    int sta=b1[v]-1;
    int bier=0;
    int gor=b2[v];
    for (int i=b1[v]; i<=gor; i++)
        bier=max(bier, min(najw[i], i-sta));
    wyn[v]=bier;
}

int main()
{
    scanf("%d%d", &n, &m);
    //n=m=1000;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            scanf("%d", &tab[i][j]);
            //tab[i][j]=1;
            tab[i][j]+=tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1];
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (tab[i][j]-tab[i-1][j]-tab[i][j-1]+tab[i-1][j-1]==0)
                continue;
            int bsa=1;
            int bsb=2000;
            int bss;
            while(bsa<bsb)
            {
                bss=(bsa+bsb+2)>>1;
                if (czyok(i, j, bss))
                    bsa=bss;
                else
                    bsb=bss-1;
            }
            tu[i][j]=bsa;
        }
    }
    //t=1000000;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        scanf("%d%d%d%d", &a1[i], &b1[i], &a2[i], &b2[i]);
        //a1[i]=b1[i]=1;
        //a2[i]=b2[i]=1000;
        wek[a1[i]][a2[i]].push_back(i);
        tak[a1[i]]=1;
    }
    for (int i=1; i<=n; i++)
    {
        if (!tak[i])
            continue;
        for (int j=1; j<=m; j++)
        {
            najw[j]=0;
        }
        for (int j=i; j<=n; j++)
        {
            int og=j-i+1;
            for (int l=1; l<=m; l++)
                najw[l]=max(najw[l], min(og, tu[j][l]));
            for (int l=0; l<wek[i][j].size(); l++)
                rob(wek[i][j][l]);
        }
    }
    for (int i=1; i<=t; i++)
        printf("%d\n", wyn[i]);
    return 0;
}