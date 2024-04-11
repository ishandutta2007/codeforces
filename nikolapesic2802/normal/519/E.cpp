#include <bits/stdc++.h>

using namespace std;
int n;
const int maxN=100001;
const int maxK=18;
int tabela[maxK][maxN];
vector<int> graf[maxN];
int subtree[maxN];
int depth[maxN];
int visiteddfs[maxN];
int subtSize(int j)
{
    visiteddfs[j]=1;
    int s=1;
    for(unsigned int i=0;i<graf[j].size();i++)
    {
        int t=graf[j][i];
        if(visiteddfs[t]==0)
        {
            s+=subtSize(t);
        }
    }
    subtree[j]=s;
    return s;
}
void napraviTabelu()
{
    queue<int> bfs;
    bfs.push(0);
    int visited[n]={};
    visited[0]=1;
    tabela[0][0]=-1;
    depth[0]=1;
    while(!bfs.empty())
    {
        int tr=bfs.front();
        bfs.pop();
        for(unsigned int i=0;i<graf[tr].size();i++)
        {
            int s=graf[tr][i];
            if(visited[s]==0)
            {
                tabela[0][s]=tr;
                depth[s]=depth[tr]+1;
                visited[s]=1;
                bfs.push(s);
            }
        }
    }
    for(int d=1;d<maxK;d++)
    {
        for(int i=0;i<n;i++)
        {
            int mid=tabela[d-1][i];
            if(mid!=-1)
                tabela[d][i]=tabela[d-1][mid];
        }
    }
}
int pomeri(int j,int k)
{
    for(int d=0;d<maxK && j!=-1;d++)
    {
        if(((1<<d)&k)>0)
        {
            j=tabela[d][j];
        }
    }
    return j;
}
int lowestCommonAnsestor(int i,int j)
{
    if(depth[i]>depth[j])
    {
        i=pomeri(i,depth[i]-depth[j]);
    }
    if(depth[i]<depth[j])
    {
        j=pomeri(j,depth[j]-depth[i]);
    }
    if(i==j)
    {
        return i;
    }
    for(int d=maxK-1;d>=0;d--)
    {
        if(tabela[d][i]!=tabela[d][j])
        {
            i=tabela[d][i];
            j=tabela[d][j];
        }
    }
    return tabela[0][i];
}
int udaljenost(int i,int j)
{
    return depth[i]+depth[j]-2*depth[lowestCommonAnsestor(i,j)];
}
map<pair<int,int>,int> resenja;
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    napraviTabelu();
    subtSize(0);
    /*for(int i=0;i<n;i++)
    {
        printf("Size od %i: %i\n",i,subtree[i]);
    }*/
    int m;
    scanf("%i",&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        int u=udaljenost(a,b);
        if(u%2==1)
        {
            printf("0\n");
        }
        else
        {
            if(u==0)
            {
                printf("%i\n",n);
            }
            else
            {
                int res=1;
                int gde;
                if(depth[a]>depth[b])
                {
                    gde=pomeri(a,u/2);
                }
                else
                {
                    gde=pomeri(b,u/2);
                }
                int p1;
                int p2;
                if(depth[a]-depth[gde]<u/2)
                {
                    p1=tabela[0][gde];
                }
                else
                {
                    p1=pomeri(a,u/2-1);
                }
                if(depth[b]-depth[gde]<u/2)
                {
                    p2=tabela[0][gde];
                }
                else
                {
                    p2=pomeri(b,u/2-1);
                }
                //printf("%i %i   %i %i %i\n",p1,p2,a,b,gde);
                if(depth[p1]<depth[gde]||depth[p2]<depth[gde])
                {
                    if(depth[p1]<depth[gde])
                    {
                        res=subtree[gde]-subtree[p2];
                    }
                    else
                    {
                        res=subtree[gde]-subtree[p1];
                    }
                }
                else
                {
                    res=n-subtree[p1]-subtree[p2];
                }
                printf("%i\n",res);
            }
        }
    }
    return 0;
}