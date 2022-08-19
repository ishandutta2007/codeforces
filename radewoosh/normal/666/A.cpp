#include <bits/stdc++.h>
using namespace std;

int n;
char wcz[1000007];

int dp[1000007][4];

string a, b;

map < string , int > mapa;

vector < string > wek;

int main()
{
    scanf("%s", wcz+1);
    for (int i=1; 1; i++)
    {
        if (!wcz[i])
        {
            n=i-1;
            break;
        }
    }
    dp[n][2]=1;
    dp[n][3]=1;
    for (int i=n-2; i>=5; i--)
    {
        for (int j=2; j<=3; j++)
        {
            a="";
            b="";
            for (int l=1; l<=j; l++)
            {
                a+=wcz[i+l];
                b+=wcz[i+j+l];
            }
            if (dp[i+j][j^1] || (dp[i+j][j] && a!=b))
            {
                dp[i][j]=1;
                if (mapa[a])
                continue;
                mapa[a]=1;
                wek.push_back(a);
            }
        }
    }
    printf("%d\n", (int)wek.size());
    sort(wek.begin(), wek.end());
    for (int i=0; i<wek.size(); i++)
    {
        for (int j=0; j<wek[i].size(); j++)
        printf("%c", wek[i][j]);
        printf("\n");
    }
    return 0;
}