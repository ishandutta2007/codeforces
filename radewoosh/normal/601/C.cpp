#include <bits/stdc++.h>
using namespace std;

int n, m;

int k;

double dps[1000007];
double dpn[1000007];

int x;

int on;

double wyn=1.0;

int main()
{
    scanf("%d%d", &n, &m);
    if (m==1)
    {
        printf("1.0000000000000\n");
        return 0;
    }
    dpn[0]=(double)m-1.0;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        on+=x;
        for (int j=0; j<=i*m+m; j++)
        {
            dps[j]=dpn[j];
            dpn[j]=0.0;
        }
        for (int j=0; j<=i*m+m; j++)
        {
            dpn[j+1]+=dps[j]/(m-1);
            dpn[j+1+m]-=dps[j]/(m-1);
        }
        for (int j=1; j<=i*m+m; j++)
        {
            dpn[j]+=dpn[j-1];
        }
        for (int j=0; j<=i*m+m; j++)
        {
            dpn[j+x]-=dps[j]/(m-1);
        }
    }
    for (int i=0; i<on; i++)
    {
        wyn+=dpn[i];
    }
    printf("%.13lf\n", wyn);
    return 0;
}