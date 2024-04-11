#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[207];

int ile[5];

int dp[207][207][207];

int a, b, c;

int main()
{
    scanf("%d", &n);
    scanf("%s", wcz+1);
    for (int i=1; i<=n; i++)
    {
        if (wcz[i]=='B')
        ile[1]++;
        if (wcz[i]=='G')
        ile[2]++;
        if (wcz[i]=='R')
        ile[3]++;
    }
    dp[ile[1]][ile[2]][ile[3]]=1;
    for (int s=n; s>=2; s--)
    {
        for (int i=0; i<=n; i++)
        {
            for (int j=0; j<=n; j++)
            {
                a=i;
                b=j;
                c=s-i-j;
                if (a<0 || b<0 || c<0 || a+b+c>n || !dp[a][b][c])
                continue;
                if (a>=2)
                dp[a-1][b][c]=1;
                if (b>=2)
                dp[a][b-1][c]=1;
                if (c>=2)
                dp[a][b][c-1]=1;
                if (a && b)
                dp[a-1][b-1][c+1]=1;
                if (a && c)
                dp[a-1][b+1][c-1]=1;
                if (b && c)
                dp[a+1][b-1][c-1]=1;
            }
        }
    }
    if (dp[1][0][0])
    printf("B");
    if (dp[0][1][0])
    printf("G");
    if (dp[0][0][1])
    printf("R");
    printf("\n");
    return 0;
}