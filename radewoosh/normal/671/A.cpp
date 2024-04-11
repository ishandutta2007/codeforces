#include <bits/stdc++.h>
using namespace std;

int n;

long long px1, py1;
long long px2, py2;
long long tx, ty;

long long x[100007];
long long y[100007];

double inf;
double dp[100007][5];

int c;

double wyn;

double odl(long long ax, long long ay, long long bx, long long by)
{
    return sqrt((double)(ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int main()
{
    scanf("%lld%lld", &px1, &py1);
    scanf("%lld%lld", &px2, &py2);
    scanf("%lld%lld", &tx, &ty);

    px1-=tx;
    py1-=ty;

    px2-=tx;
    py2-=ty;

    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
        x[i]-=tx;
        y[i]-=ty;
    }

    inf=300000000.0;
    inf*=inf;

    dp[0][1]=inf;
    dp[0][2]=inf;
    dp[0][3]=inf;

    for (int i=1; i<=n; i++)
    {
        dp[i][0]=inf;
        dp[i][1]=inf;
        dp[i][2]=inf;
        dp[i][3]=inf;
        for (int j=0; j<=1; j++)
        {
            for (int l=0; l<=1; l++)
            {
                c=((j*1)^(l*2));
                if (!j)
                {
                    dp[i][c|1]=min(dp[i][c|1], dp[i-1][c]+odl(px1, py1, x[i], y[i])+odl(0, 0, x[i], y[i]));
                }

                if (!l)
                {
                    dp[i][c|2]=min(dp[i][c|2], dp[i-1][c]+odl(px2, py2, x[i], y[i])+odl(0, 0, x[i], y[i]));
                }

                dp[i][c]=min(dp[i][c], dp[i-1][c]+odl(0, 0, x[i], y[i])+odl(0, 0, x[i], y[i]));

            }
        }
    }

    wyn=inf;

    wyn=min(wyn, dp[n][1]);
    wyn=min(wyn, dp[n][2]);
    wyn=min(wyn, dp[n][3]);

    printf("%.10lf\n", wyn);

    return 0;
}