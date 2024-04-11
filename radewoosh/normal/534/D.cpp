#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int tab[1000007];
vector <int> ile[1000007];

int m;
vector <int> wek;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        ile[tab[i]].push_back(i);
    }
    m=0;
    for (int i=1; i<=n; i++)
    {
        while(m>=3 && ile[m].empty())
        {
            m-=3;
        }
        if (ile[m].empty())
        {
            printf("Impossible");
            return 0;
        }
        wek.push_back(ile[m].back());
        ile[m].pop_back();
        m++;
    }
    printf("Possible\n");
    for (int i=0; i<n; i++)
    {
        printf("%d ", wek[i]);
    }
    return 0;
}