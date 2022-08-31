#include <bits/stdc++.h>
using namespace std;

int n, m;

char tab[1000007];

int ile;

int g;
char co[1];

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", tab);
    for (int i=1; i<n; i++)
    {
        if (tab[i]=='.' && tab[i-1]=='.')
        ile++;
    }
    while(m--)
    {
        scanf("%d%s", &g, co);
        g--;
        if (co[0]=='.')
        {
            printf("%d\n", ile+(g!=0 && tab[g]!='.' && tab[g-1]=='.')+(g<n-1 && tab[g]!='.' && tab[g+1]=='.'));
            ile+=(g!=0 && tab[g]!='.' && tab[g-1]=='.')+(g<n-1 && tab[g]!='.' && tab[g+1]=='.');
        }
        else
        {
            printf("%d\n", ile-(g!=0 && tab[g]=='.' && tab[g-1]=='.')-(g<n-1 && tab[g]=='.' && tab[g+1]=='.'));
            ile+=-(g!=0 && tab[g]=='.' && tab[g-1]=='.')-(g<n-1 && tab[g]=='.' && tab[g+1]=='.');
        }
        tab[g]=co[0];
    }
    return 0;
}