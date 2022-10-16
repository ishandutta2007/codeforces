#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    vector<vector<int> > graf(n+2);
    //set<int> grane[n];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        //grane[a].insert(b);
        //grane[b].insert(a);
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int a;
    scanf("%i",&a);
    if(a!=1)
    {
        printf("No\n");
        return 0;
    }
    int dubina[n+2]={};
    int visited[n+2]={};
    visited[1]=1;
    set<int>::iterator it;
    queue<set<int> > pokupiti;
    set<int> a1;
    for(int i=0;i<graf[1].size();i++)
    {
        int sl=graf[1][i];
        if(visited[sl]==0)
        {
            a1.insert(sl);
            //printf("Dodajem %i na set\n",sl);
            visited[sl]=1;
        }
    }
    pokupiti.push(a1);
    for(int i=0;i<n-1;i++)
    {
        if(pokupiti.front().size()==0)
        {
            pokupiti.pop();
        }
        scanf("%i",&a);
        //printf("Usao za %i\n",a);

        /*for(it=pokupiti.front().begin();it!=pokupiti.front().end();it++)
        {
            printf("Ocekujem %i\n",*it);
        }*/
        if(!pokupiti.front().count(a))
        {
            printf("No\n");
            return 0;
        }
        pokupiti.front().erase(a);
        set<int> a2;
        for(int i=0; i<graf[a].size(); i++)
        {
            int sl=graf[a][i];
            if(visited[sl]==0)
            {
                a2.insert(sl);
                visited[sl]=1;
            }
        }
        if(!a2.empty())
        {
            pokupiti.push(a2);
        }
    }
    printf("Yes\n");
    return 0;
}