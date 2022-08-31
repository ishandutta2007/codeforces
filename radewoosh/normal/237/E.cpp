#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int n1;
char wcz[107];

vector <int> graf[507];
int mac[507][507];
int kosz[507][507];

int p;

int odl[507];
int bylo[507];
int wyn;

void bellman()
{
     for (int i=1; i<=n1; i++)
     {
         odl[i]=1000000000;
         bylo[i]=0;
     }
     odl[1]=0;
     for (int i=1; i<n1; i++)
     {
         for (int j=1; j<=n1; j++)
         {
             if (odl[j]==1000000000)
             {
                                    continue;
             }
             for (int l=0; l<graf[j].size(); l++)
             {
                 if (!mac[j][graf[j][l]])
                 {
                                         continue;
                 }
                 odl[graf[j][l]]=min(odl[graf[j][l]], odl[j]+kosz[j][graf[j][l]]);
             }
         }
     }
}

int przep(int v)
{
    bylo[v]=1;
    if (v==n1)
    return 1;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (!bylo[graf[v][i]] && mac[v][graf[v][i]] && odl[graf[v][i]]==odl[v]+kosz[v][graf[v][i]] && przep(graf[v][i]))
        {
                              mac[v][graf[v][i]]--;
                              mac[graf[v][i]][v]++;
                              return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%s", &wcz);
    for (int i=0; 1; i++)
    {
        if (!wcz[i])
        {
                    n=i;
                    break;
        }
        mac[1][wcz[i]-'a'+2]++;
    }
    scanf("%d", &m);
    for (int i=2; i<=27; i++)
    {
        graf[1].push_back(i);
        graf[i].push_back(1);
    }
    n1=1+26+m+1;
    for (int i=27+1; i<=27+m; i++)
    {
        for (int j=2; j<=27; j++)
        {
            graf[i].push_back(j);
            graf[j].push_back(i);
        }
    }
    for (int i=27+1; i<=27+m; i++)
    {
        graf[i].push_back(n1);
        graf[n1].push_back(i);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%s", &wcz);
        for (int j=0; 1; j++)
        {
            if (!wcz[j])
            break;
            mac[wcz[j]-'a'+2][27+i]++;
        }
        scanf("%d", &p);
        mac[27+i][n1]=p;
        kosz[27+i][n1]=i;
        kosz[n1][27+i]=-i;
    }
    for (int i=1; i<=n; i++)
    {
        bellman();
        if (!przep(1))
        {
                      printf("-1");
                      return 0;
        }
    }
    for (int i=28; i<n1; i++)
    {
        wyn+=kosz[i][n1]*mac[n1][i];
    }
    printf("%d", wyn);
    return 0;
}