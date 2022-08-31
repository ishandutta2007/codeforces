#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

char tab[507][507];
int bylo[507][507];

pair <int,int> s, k;

int ile;

void dfs(int x, int y)
{
    if (tab[x][y]=='X' && make_pair(x, y)!=s)
    return;
    bylo[x][y]=1;
    if (x>0 && !bylo[x-1][y])
    {
        dfs(x-1, y);
    }
    if (y>0 && !bylo[x][y-1])
    {
        dfs(x, y-1);
    }
    if (x<n-1 && !bylo[x+1][y])
    {
        dfs(x+1, y);
    }
    if (y<m-1 && !bylo[x][y+1])
    {
        dfs(x, y+1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%s", tab[i]);
    }
    scanf("%d%d%d%d", &s.first, &s.second, &k.first, &k.second);
    s.first--;
    s.second--;
    k.first--;
    k.second--;
    dfs(s.first, s.second);
    if (k.first>0)
    {
        ile+=bylo[k.first-1][k.second];
    }
    if (k.second>0)
    {
        ile+=bylo[k.first][k.second-1];
    }
    if (k.first<n)
    {
        ile+=bylo[k.first+1][k.second];
    }
    if (k.second<m)
    {
        ile+=bylo[k.first][k.second+1];
    }
    if ((tab[k.first][k.second]=='.' && ile>=2) || (tab[k.first][k.second]=='X' && ile>=1))
    printf("YES");
    else
    printf("NO");
    return 0;
}