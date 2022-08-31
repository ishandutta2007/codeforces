#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;

char tab[1000007];

int m=1;
vector <int> zle[1000007];
vector <int> dob[1000007];
int co[800007][26];
vector <int> graf[1000007];
int l;

int pas[1000007];
long long wyn;


void dfs(int v, int odl)
{
    int p;
    for (int i=0; i<graf[v].size(); i++)
    {
        p=graf[v][i];
        dfs(p, odl+1);
        for (int j=0; j<zle[p].size(); j++)
        {
            zle[v].push_back(zle[p][j]);
        }
        for (int j=0; j<dob[p].size(); j++)
        {
            dob[v].push_back(dob[p][j]);
        }
    }
    while(!zle[v].empty() && !dob[v].empty())
    {
        pas[zle[v].back()]=dob[v].back();
        wyn+=odl;
        zle[v].pop_back();
        dob[v].pop_back();
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", tab);
        l=1;
        for (int j=0; 1; j++)
        {
            if (!tab[j])
            {
                zle[l].push_back(i);
                break;
            }
            if (co[l][tab[j]-'a'])
            {
                l=co[l][tab[j]-'a'];
            }
            else
            {
                m++;
                co[l][tab[j]-'a']=m;
                graf[l].push_back(m);
                l=m;
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%s", tab);
        l=1;
        for (int j=0; 1; j++)
        {
            if (!tab[j])
            {
                dob[l].push_back(i);
                break;
            }
            if (co[l][tab[j]-'a'])
            {
                l=co[l][tab[j]-'a'];
            }
            else
            {
                m++;
                co[l][tab[j]-'a']=m;
                graf[l].push_back(m);
                l=m;
            }
        }
    }
    dfs(1, 0);
    printf("%lld\n", wyn);
    for (int i=1; i<=n; i++)
    {
        printf("%d %d\n", i, pas[i]);
    }
    return 0;
}