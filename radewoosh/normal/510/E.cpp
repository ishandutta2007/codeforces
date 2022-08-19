#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
int tab[507];
vector < pair <int,int> > jed;
vector < pair <int,int> > dwa;

int n1;
vector <int> graf[507];
int mac[507][507];
int bylo[507];

int bylos[507];
vector <int> sa[507];
vector <int> sto[507];
int l;

int czypie(int v)
{
    for (int i=2; i*i<=v; i++)
    {
        if (!(v%i))
        return 0;
    }
    return 1;
}

int dfs(int v)
{
    bylo[v]=1;
    if (v==n1)
    {
              return 1;
    }
    for (int i=0; i<graf[v].size(); i++)
    {
        if (!bylo[graf[v][i]] && mac[v][graf[v][i]] && dfs(graf[v][i]))
        {
                              mac[v][graf[v][i]]--;
                              mac[graf[v][i]][v]++;
                              //printf("%d ", v);
                              return 1;
        }
    }
    return 0;
}

void lacz(int v)
{
     bylos[v]=1;
     sto[l].push_back(v);
     if (!bylos[sa[v][0]])
     {
                          lacz(sa[v][0]);
     }
     if (!bylos[sa[v][1]])
     {
                          lacz(sa[v][1]);
     }
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    n1=(n+1)<<1;
    for (int i=1; i<=n; i++)
    {
    	if (tab[i]&1)
    	{
    	    mac[1][i+1]=2;
    	    graf[1].push_back(i+1);
    	    graf[i+1].push_back(1);
    	}
        else
        {
        	mac[n+i+1][n1]=2;
        	graf[n1].push_back(n+i+1);
       		graf[n+i+1].push_back(n1);
    	}
    }
    /*for (int i=1; i<=n1; i++)
    {
    	printf("%d\n", i);
    	for (int j=0; j<graf[i].size(); j++)
    	{
    		printf("%d %d\n", graf[i][j], mac[i][graf[i][j]]);
    	}
    }*/
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (tab[i]&1 && czypie(tab[i]+tab[j]))
            {
                                   //printf("%d %d   %d\n", jed[i].first, dwa[j].first, jed[i].first+dwa[j].first);
                                   mac[1+i][n+1+j]=1;
                                   graf[1+i].push_back(n+1+j);
                                   graf[n+1+j].push_back(1+i);
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n1; j++)
        {
            bylo[j]=0;
        }
        if (!dfs(1))
        {
                    printf("Impossible");
                    return 0;
        }
        //printf("\n");
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (mac[n+1+j][1+i])
            {
				sa[i].push_back(j);
                sa[j].push_back(i);
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (!bylos[i])
        {
                      l++;
                      lacz(i);
        }
    }
    printf("%d\n", l);
    for (int i=1; i<=l; i++)
    {
        printf("%d", sto[i].size());
        for (int j=0; j<sto[i].size(); j++)
        printf(" %d", sto[i][j]);
        printf("\n");
    }
    return 0;
}