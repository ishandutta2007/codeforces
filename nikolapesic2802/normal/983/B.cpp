#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int niz[n];
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
    int dp[n][n];
    int maksimum[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
            maksimum[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
        dp[i][i]=niz[i];
    for(int r=1;r<n;r++)
    {
        for(int i=0;i<n-r;i++)
        {
            dp[i][i+r]=dp[i+1][i+r]^dp[i][i+r-1];
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5i ",dp[i][j]);
        }
        printf("\n");
    }*/
    for(int i=0;i<n;i++)
        maksimum[i][i]=dp[i][i];
    for(int r=1;r<n;r++)
    {
        for(int i=0;i<n-r;i++)
        {
            maksimum[i][i+r]=max(max(maksimum[i+1][i+r],maksimum[i][i+r-1]),dp[i][i+r]);
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5i ",maksimum[i][j]);
        }
        printf("\n");
    }*/
    int q;
    scanf("%i",&q);
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        printf("%i\n",maksimum[a][b]);
    }
    return 0;
}