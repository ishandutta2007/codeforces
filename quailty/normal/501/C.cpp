#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1<<16;
struct node
{
    int d,s;
}p[MAXN+5];
vector<pair<int,int> >ans;
void bfs(int st)
{
    queue<int>q;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        p[u].d--;
        q.pop();
        int v=p[u].s;
        ans.push_back(make_pair(u,v));
        p[v].d--;
        p[v].s^=u;
        if(p[v].d==1)q.push(v);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].d,&p[i].s);
    for(int i=0;i<n;i++)
        if(p[i].d==1)bfs(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}