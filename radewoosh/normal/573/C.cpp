#include <bits/stdc++.h>
using namespace std;

int n;

int p1, p2;
vector <int> graf[1000007];

//int wyw[1000007];

//int tak[1000007];
int lis[1000007];
int lis2[1000007];

int licz;

/*void czys(int v)
{
    for (int i=0; i<graf[v].size(); i++)
    {
        if (wyw[graf[v][i]])
        {
            swap(graf[v][i], graf[v].back());
            graf[v].pop_back();
            i--;
        }
    }
}*/

void oz(int v)
{
    lis[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    if (graf[graf[v][i]].size()==2 && !lis[graf[v][i]])
    oz(graf[v][i]);
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<n; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
        graf[p2].push_back(p1);
    }
    /*for (int i=1; i<=n; i++)
    {
        czys(i);
        if (graf[i].size()==2)
        {
            p1=graf[i][0];
            p2=graf[i][1];
            wyw[i]=1;
            graf[p1].push_back(p2);
            graf[p2].push_back(p1);
            graf[i].clear();
        }
    }
    for (int i=1; i<=n; i++)
    {
        czys(i);
    }
    for (int i=1; i<=n; i++)
    {
        if (!wyw[i] && graf[i].size()>2)
        {
            tak[i]=1;
        }
        if (graf[i].size()==3)
        {
            licz=0;
            for (int j=0; j<3; j++)
            {
                if (graf[graf[i][j]].size()==1)
                {
                    licz++;
                }
            }
            if (licz==2)
            tak[i]=0;
        }
        printf("%d %d\n", i, tak[i]);
    }
    for (int i=1; i<=n; i++)
    {
        if (!wyw[i] && tak[i])
        {
            licz=0;
            for (int j=0; j<graf[i].size(); j++)
            {
                if (tak[graf[i][j]])
                {
                    licz++;
                }
            }
            if  (licz>2)
            {
                printf("No\n");
                return 0;
            }
        }
    }*/
    for (int i=1; i<=n; i++)
    {
        if (graf[i].size()==1)
        {
            oz(i);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (lis[i])
        {
            lis2[i]=1;
            continue;
        }
        if (graf[i].size()<=3)
        {
            licz=0;
            for (int j=0; j<graf[i].size(); j++)
            licz+=lis[graf[i][j]];
            if (graf[i].size()-licz<=1)
            lis2[i]=1;
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (!lis2[i])
        {
            licz=0;
            for (int j=0; j<graf[i].size(); j++)
            {
                if (!lis2[graf[i][j]])
                {
                    licz++;
                }
            }
            if  (licz>2)
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}