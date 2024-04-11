#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > graf;
const int N=100002;
int a[N];
int dist[N],sizee[N],visited[N][101],dubina[N][101];
int main()
{
    int n,m,k,s;
    scanf("%i %i %i %i",&n,&m,&k,&s);
    vector<int> pom;
    queue<pair<int,int> > big_bfs;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&a[i]);
        graf.push_back(pom);
        big_bfs.push(make_pair(i,a[i]));
        visited[i][a[i]]=1;
    }
    for(int i=0;i<m;i++)
    {
        int a1,b1;
        scanf("%i %i",&a1,&b1);
        a1--;
        b1--;
        graf[a1].push_back(b1);
        graf[b1].push_back(a1);
    }
    while(!big_bfs.empty())
    {
        pair<int,int> tr=big_bfs.front();
        big_bfs.pop();
        if(sizee[tr.first]<s)
        {
            dist[tr.first]+=dubina[tr.first][tr.second];
            sizee[tr.first]++;
        }
        for(int i=0;i<graf[tr.first].size();i++)
        {
            int sl=graf[tr.first][i];
            if(visited[sl][tr.second]==0)
            {
                dubina[sl][tr.second]=dubina[tr.first][tr.second]+1;
                visited[sl][tr.second]=1;
                big_bfs.push(make_pair(sl,tr.second));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%i ",dist[i]);
    }
    return 0;
}