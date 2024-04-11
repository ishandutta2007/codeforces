#include <bits/stdc++.h>
using namespace std;

char tab[10][10];

int p1=1000000;
int p2=1000000;

int main()
{
    for (int i=1; i<=8; i++)
    {
        scanf("%s", tab[i]+1);
    }
    for (int i=1; i<=8; i++)
    {
        for (int j=1; j<=8; j++)
        {
            if (tab[j][i]!='.')
            {
                if (tab[j][i]=='W')
                {
                    p1=min(p1, j-1);
                }
                break;
            }
        }
        for (int j=8; j; j--)
        {
            if (tab[j][i]!='.')
            {
                if (tab[j][i]=='B')
                {
                    p2=min(p2, 8-j);
                }
                break;
            }
        }
    }
    if (p1<=p2)
    {
        printf("A\n");
    }
    else
    {
        printf("B\n");
    }
    return 0;
}