#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    int matrica[n+2][m+2];
    int zapravo[n+2][m+2];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            zapravo[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            scanf(" %c",&c);
            //printf("\n%c\n",c);
            if(c=='*')
            {
                matrica[i][j]=-1;
                zapravo[i-1][j-1]++;
                zapravo[i-1][j]++;
                zapravo[i-1][j+1]++;
                zapravo[i][j-1]++;
                zapravo[i][j+1]++;
                zapravo[i+1][j-1]++;
                zapravo[i+1][j]++;
                zapravo[i+1][j+1]++;
                zapravo[i][j]=-100;
            }
            else
            {
                if(c=='.')
                {
                    matrica[i][j]=0;
                }
                else
                {
                    matrica[i][j]=c-'0';
                }
            }
        }
    }
    bool test=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(matrica[i][j]<0&&zapravo[i][j]<0)
            {

            }
            else
            {
                if(matrica[i][j]<0||zapravo[i][j]<0)
                {
                    test=false;
                }
                else
                {
                    if(matrica[i][j]!=zapravo[i][j])
                    {
                        test=false;
                    }
                }
            }
        }
    }
    if(test)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}