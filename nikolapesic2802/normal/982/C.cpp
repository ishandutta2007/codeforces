#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > graf;
int subtree[100001];
int dfs(int tr,int par)
{
    int t=1;
    for(int i=0;i<graf[tr].size();i++)
    {
        if(graf[tr][i]!=par)
        {
            t+=dfs(graf[tr][i],tr);
        }
    }
    subtree[tr]=t;
    return t;
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> t;
    for(int i=0;i<n;i++)
        graf.push_back(t);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    subtree[0]=dfs(0,0);
    if(n%2==1)
    {
        printf("-1\n");
    }
    else
    {
        int broj=-1;
        for(int i=0;i<n;i++)
        {
            //printf("%i\n",subtree[i]);
            if(subtree[i]%2==0)
            {
                broj++;
            }
        }
        printf("%i\n",broj);
    }
    return 0;
}