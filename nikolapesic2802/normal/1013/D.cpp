#include <bits/stdc++.h>

using namespace std;
int visited[400001];
int main()
{
    int n,m,q;
    scanf("%i %i %i",&n,&m,&q);
    int b=n+m;
    vector<vector<int> > graph(b);
    for(int i=0;i<q;i++)
    {
        int aa,bb;
        scanf("%i %i",&aa,&bb);
        aa--;
        bb+=n-1;
        graph[aa].push_back(bb);
        graph[bb].push_back(aa);
    }
    int broj=0;
    for(int i=0;i<b;i++)
    {
        if(visited[i]==0)
        {
            broj++;
            queue<int> bfs;
            bfs.push(i);
            while(!bfs.empty())
            {
                int tr=bfs.front();
                visited[tr]=1;
                bfs.pop();
                for(unsigned int j=0;j<graph[tr].size();j++)
                {
                    int sl=graph[tr][j];
                    if(visited[sl]==0)
                    {
                        bfs.push(sl);
                        visited[sl]=1;
                    }
                }
            }
        }
    }
    //LOOOOOL!
    printf("%i\n",broj-1);
    return 0;
}