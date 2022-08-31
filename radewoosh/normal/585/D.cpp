#include <bits/stdc++.h>
using namespace std;

int n;

int tab[5][30];

map < pair <int,int> , int > mapa;
pair <int,int> para;

int warw[2000007];
int l;

int wyb[30];

int zm[5];

int szukpo;
int szukkon;

int wyno;

vector <string> wyn;

void check1()
{
    l++;
    for (int i=1; i<=3; i++)
    {
        zm[i]=0;
    }
    for (int i=1; i<=(n/2); i++)
    {
        for (int j=1; j<=3; j++)
        {
            zm[j]+=tab[j][i]*(wyb[i]!=j);
        }
    }
    warw[l]=zm[1];
    para=make_pair(zm[1]-zm[2], zm[1]-zm[3]);
    if (!mapa[para] || warw[mapa[para]]<warw[l])
    {
        mapa[para]=l;
    }
}

void rek1(int v)
{
    if (v==(n/2)+1)
    {
        check1();
        return;
    }
    wyb[v]=1;
    rek1(v+1);
    wyb[v]=2;
    rek1(v+1);
    wyb[v]=3;
    rek1(v+1);
}

void check2()
{
    l++;
    for (int i=1; i<=3; i++)
    {
        zm[i]=0;
    }
    for (int i=(n/2)+1; i<=n; i++)
    {
        for (int j=1; j<=3; j++)
        {
            zm[j]+=tab[j][i]*(wyb[i]!=j);
        }
    }
    int wyntu=zm[1];
    para=make_pair(-zm[1]+zm[2], -zm[1]+zm[3]);
    if (!mapa[para])
    {
        return;
    }
    if (!szukpo || warw[mapa[para]]+wyntu>wyno)
    {
        wyno=warw[mapa[para]]+wyntu;
        szukpo=mapa[para];
        szukkon=l;
    }
}

void rek2(int v)
{
    if (v==(n+1))
    {
        check2();
        return;
    }
    wyb[v]=1;
    rek2(v+1);
    wyb[v]=2;
    rek2(v+1);
    wyb[v]=3;
    rek2(v+1);
}

void check3()
{
    for (int i=1; i<=(n/2); i++)
    {
        if (wyb[i]==1)
        printf("MW\n");
        if (wyb[i]==2)
        printf("LW\n");
        if (wyb[i]==3)
        printf("LM\n");
    }
}

void rek3(int v)
{
    if (v==(n/2)+1)
    {
        l++;
        if (l!=szukpo)
        return;
        check3();
        return;
    }
    wyb[v]=1;
    rek3(v+1);
    wyb[v]=2;
    rek3(v+1);
    wyb[v]=3;
    rek3(v+1);
}

void check4()
{
    for (int i=(n/2)+1; i<=n; i++)
    {
        if (wyb[i]==1)
        printf("MW\n");
        if (wyb[i]==2)
        printf("LW\n");
        if (wyb[i]==3)
        printf("LM\n");
    }
}

void rek4(int v)
{
    if (v==(n+1))
    {
        l++;
        if (l!=szukkon)
        return;
        check4();
        return;
    }
    wyb[v]=1;
    rek4(v+1);
    wyb[v]=2;
    rek4(v+1);
    wyb[v]=3;
    rek4(v+1);
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d%d", &tab[1][i], &tab[2][i], &tab[3][i]);
    }
    l=0;
    rek1(1);
    l=0;
    rek2((n/2)+1);
    if (!szukpo)
    {
        printf("Impossible\n");
        return 0;
    }
    l=0;
    rek3(1);
    l=0;
    rek4((n/2)+1);
    return 0;
}