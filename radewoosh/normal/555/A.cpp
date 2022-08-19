#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int k;

int ile;

int wyn;

int a;
vector <int> wek;

int naj;

int onaj;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=k; i++)
    {
        scanf("%d", &ile);
        wek.clear();
        for (int j=1; j<=ile; j++)
        {
            scanf("%d", &a);
            wek.push_back(a);
        }
        if (wek[0]==1)
        {
            for (int j=0; j<wek.size(); j++)
            {
                if (wek[j]==j+1)
                {
                    naj=j+1;
                }
            }
        }
        //for (int j=1; j<ile; j++)
        //{
        //    if (wek[j]!=(wek[j-1]+1))
        //    wyn++;
        //}
        wyn+=ile-1;
    }
    wyn=wyn-(naj-1)+n-1-(naj-1);
    printf("%d", wyn);
    return 0;
}