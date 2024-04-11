#include <bits/stdc++.h>
using namespace std;

int n;

double tab[1007][1007];

int jusz[1007];

double tak[1007];
double wyn[1007];

double tam;
double tu;

double nie;

int v;

int zero(double v)
{
    return abs(v)<0.000000001;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            scanf("%lf", &tab[i][j]);
            tab[i][j]/=100.0;
        }
    }
    jusz[n]=1;
    for (int i=1; i<n; i++)
    {
        tak[i]=tab[i][n];
        wyn[i]=tak[i];
    }
    for (int h=1; h<n; h++)
    {
        tam=1000000000.0;
        v=-1;
        for (int i=1; i<=n; i++)
        {
            if (jusz[i] || zero(tak[i]))
            continue;
            nie=1.0-tak[i];
            if (zero(nie))
            {
                tu=wyn[i];
            }
            else
            {
                tu=wyn[i]/tak[i]+(nie/(1.0-nie));
            }
            if (tu<tam)
            {
                tam=tu;
                v=i;
            }
        }
        if (v==-1)
        break;
        jusz[v]=1;
        wyn[v]=tam;
        for (int i=1; i<=n; i++)
        {
            if (jusz[i] || zero(tab[i][v]))
            continue;
            nie=1.0-tak[i];
            wyn[i]+=nie*tab[i][v]*(wyn[v]+1.0);
            nie*=(1.0-tab[i][v]);
            tak[i]=1.0-nie;
        }
    }
    printf("%.9lf\n", wyn[1]);
    return 0;
}