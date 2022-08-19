#include <iostream>
#include <cstdio>
using namespace std;

int n;
int tab[1000007];
int p;

int mini[1000007];
int maxi[1000007];

int k=1000000;
int licz[2000007];

long long wyn;

void odp1(int a, int b, int s)
{
    for (int i=a; i<=s; i++)
    {
        if (i+maxi[i]-mini[i]>s && i+maxi[i]-mini[i]<=b && mini[i+maxi[i]-mini[i]]>mini[i] && maxi[i+maxi[i]-mini[i]]<maxi[i])
        {
            wyn++;
        }
    }
}

void odp1b(int a, int b, int s)
{
    for (int i=s+1; i<=b; i++)
    {
        if (i-maxi[i]+mini[i]>=a && i-maxi[i]+mini[i]<=s && mini[i-maxi[i]+mini[i]]>mini[i] && maxi[i-maxi[i]+mini[i]]<maxi[i])
        {
            wyn++;
        }
    }
}

void odp2(int a, int b, int s)
{
    int aa=s+1;
    int bb=s;
    for (int i=s; i>=a; i--)
    {
        while(aa<=b && maxi[aa]<maxi[i])
        {
            if (aa<=bb)
            {
                licz[k+maxi[aa]-aa]--;
            }
            aa++;
        }
        while(bb<b && mini[bb+1]>mini[i])
        {
            bb++;
            if (aa<=bb)
            {
                licz[k+maxi[bb]-bb]++;
            }
        }
        wyn+=licz[k+mini[i]-i];
    }
    for (int i=s+1; i<=b; i++)
    {
        licz[k+maxi[i]-i]=0;
    }
}

void odp2b(int a, int b, int s)
{
    int aa=s;
    int bb=s+1;
    for (int i=s+1; i<=b; i++)
    {
        while(aa>=a && maxi[aa]<maxi[i])
        {
            if (aa>=bb)
            {
                licz[k+maxi[aa]+aa]--;
            }
            aa--;
        }
        while(bb>a && mini[bb-1]>mini[i])
        {
            bb--;
            if (aa>=bb)
            {
                licz[k+maxi[bb]+bb]++;
            }
        }
        wyn+=licz[k+mini[i]+i];
    }
    for (int i=s; i>=a; i--)
    {
        licz[k+maxi[i]+i]=0;
    }
}

void rek(int a, int b)
{
    if (a==b)
    {
        wyn++;
        return;
    }
    int s=(a+b)>>1;
    maxi[s]=mini[s]=tab[s];
    maxi[s+1]=mini[s+1]=tab[s+1];
    for (int i=s-1; i>=a; i--)
    {
        mini[i]=min(tab[i], mini[i+1]);
        maxi[i]=max(tab[i], maxi[i+1]);
    }
    for (int i=s+2; i<=b; i++)
    {
        mini[i]=min(tab[i], mini[i-1]);
        maxi[i]=max(tab[i], maxi[i-1]);
    }
    odp1(a, b, s);
    odp1b(a, b, s);
    odp2(a, b, s);
    odp2b(a, b, s);
    rek(a, (a+b)>>1);
    rek((a+b+2)>>1, b);
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &p);
        scanf("%d", &tab[p]);
    }
    rek(1, n);
    printf("%lld", wyn);
    return 0;
}