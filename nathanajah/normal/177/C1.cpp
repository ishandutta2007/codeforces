#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n,k,m;
vector <int> hate[3000];
vector <int> like[3000];
int i,j,jj;
int t1,t2;
bool sudah[3000];
vector <int> soltemp;
bool cant[3000];
bool bisa;
int maxi;

void dfs(int x)
{
    soltemp.push_back(x);
    int i;
    bool ret;
    for (i=0;i<hate[x].size();++i)
        cant[hate[x][i]]=true;
    for (i=0;i<like[x].size();++i)
    {
        if (!sudah[like[x][i]])
        {
            sudah[like[x][i]]=true;
            dfs(like[x][i]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    for (i=0;i<k;++i)
    {
        scanf("%d %d",&t1,&t2);
        like[t1].push_back(t2);
        like[t2].push_back(t1);
    }
    scanf("%d",&m);
    for (i=0;i<m;++i)
    {
        scanf("%d %d",&t1,&t2);
        hate[t1].push_back(t2);
        hate[t2].push_back(t1);
    }
    for (i=1;i<=n;++i)
        if (!sudah[i])
        {
            soltemp.clear();
            sudah[i]=true;
            dfs(i);
            bisa=true;
            for (j=0;j<soltemp.size();++j)
                bisa=bisa && !cant[soltemp[j]];
            if (bisa)
                maxi=max(maxi,(int)soltemp.size());
            memset(cant,0,sizeof(cant));
        }
    printf("%d\n",maxi);
}