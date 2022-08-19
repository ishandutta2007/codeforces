#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int k, n;
int n1;
char slo1[2000007];
char slo2[2000007];

vector <int> graf[507];
int mac[507][507];
int kosz[507][507];

int p1, p2;

int odl[507];
int bylo[507];
int wyn;

int ilep()
{
    int ret=0;
    for (int i=n+1; i<n1; i++)
    {
        ret+=mac[n1][i];
    }
    return ret;
}

int dfs(int v)
{
    if (v==n1)
    return 1;
    bylo[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (!bylo[graf[v][i]] && mac[v][graf[v][i]] && odl[v]+kosz[v][graf[v][i]]==odl[graf[v][i]] && dfs(graf[v][i]))
        {
                              mac[v][graf[v][i]]--;
                              mac[graf[v][i]][v]++;
                              return 1;
        }
    }
    return 0;
}

void przep()
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
             continue;
             for (int l=0; l<graf[j].size(); l++)
             {
                 if (mac[j][graf[j][l]])
                 odl[graf[j][l]]=min(odl[graf[j][l]], odl[j]+kosz[j][graf[j][l]]);
             }
         }
     }
     //for (int i=1; i<=n1; i++)
     //{
     //    printf("%d.%d ", i, odl[i]);
     //}
     //printf("\n");
     dfs(1);
}

int main()
{
	scanf("%d%d", &k, &n);
	scanf("%s", &slo1);
	scanf("%s", &slo2);
    n1=((n+1)<<1);
    for (int i=2; i<=n+1; i++)
    {
        for (int j=n+2; j<=(n<<1)+1; j++)
        {
            kosz[i][j]=1000000;
            kosz[j][i]=-1000000;
            mac[i][j]=1;
            graf[i].push_back(j);
            graf[j].push_back(i);
        }
    }
    for (int i=2; i<=n+1; i++)
    {
        mac[1][i]=1;
        graf[1].push_back(i);
        graf[i].push_back(1);
    }
    for (int i=n+2; i<=(n<<1)+1; i++)
    {
        mac[i][n1]=1;;
        graf[n1].push_back(i);
        graf[i].push_back(n1);
    }
    for (int i=0; i<k; i++)
    {
        if (slo1[i]<='z' && slo1[i]>='a')
        {
                         p1=slo1[i]-'a'+1;
        }
        else
        {
            p1=slo1[i]-'A'+1+26;
        }
        
        if (slo2[i]<='z' && slo2[i]>='a')
        {
                         p2=slo2[i]-'a'+1;
        }
        else
        {
            p2=slo2[i]-'A'+1+26;
        }
        
        p1++;
        p2+=n+1;
        
        kosz[p1][p2]--;
        kosz[p2][p1]++;
    }
    for (int i=1; i<=n; i++)
    {
        przep();
    }
    for (int i=2; i<=n+1; i++)
    {
        for (int j=n+2; j<n1; j++)
        {
            if (mac[j][i]==1)
            {
            				 wyn+=1000000-kosz[i][j];
                             break;
            }
        }
    }
    printf("%d\n", wyn);
    for (int i=2; i<=n+1; i++)
    {
        for (int j=n+2; j<n1; j++)
        {
            if (mac[j][i]==1)
            {
            				 p1=j-n-1;
                             if (p1<=26)
                             printf("%c", 'a'+p1-1);
                             else
                             printf("%c", 'A'+p1-26-1);
                             break;
            }
        }
    }
    //system("pause");
    return 0;
}