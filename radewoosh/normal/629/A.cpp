#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[107][107];

int wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", wcz[i]+1);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int l=j+1; l<=n; l++)
            {
                if (wcz[i][j]=='C' && wcz[i][l]=='C')
                wyn++;
                if (wcz[j][i]=='C' && wcz[l][i]=='C')
                wyn++;
            }
        }
    }
    printf("%d\n", wyn);
    return 0;
}