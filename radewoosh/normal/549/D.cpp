#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

char tab[107][107];

int wyn;

int razyile[107];

int x;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%s", tab[i]);
    }
    for (int i=n-1; i>=0; i--)
    {
        for (int j=m-1; j>=0; j--)
        {
            if (tab[i][j]=='W')
            {
                if (razyile[j]!=1)
                {
                    wyn++;
                    x=1-razyile[j];
                    for (int l=0; l<=j; l++)
                    {
                        razyile[l]+=x;
                    }
                }
            }
            else
            {
                if (razyile[j]!=-1)
                {
                    wyn++;
                    x=-1-razyile[j];
                    for (int l=0; l<=j; l++)
                    {
                        razyile[l]+=x;
                    }
                }
            }
        }
    }
    printf("%d", wyn);
    return 0;
}