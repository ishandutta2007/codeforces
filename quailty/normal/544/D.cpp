#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m;
vector<int>e[3005];
int d[3005][3005];
queue<int>q;
void bfs(int st)
{
    q.push(st);
    d[st][st]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<e[p].size();i++)
        {
            if(d[st][e[p][i]]>d[st][p]+1)
            {
                d[st][e[p][i]]=d[st][p]+1;
                q.push(e[p][i]);
            }
        }
    }
}
inline int min(int &a,int &b)
{
    return a<b;
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            d[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++)
    {
        bfs(i);
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    */
    int s1,t1,l1,s2,t2,l2;
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    int mini=(d[s1][t1]<=l1 && d[s2][t2]<=l2 ? d[s1][t1]+d[s2][t2] : INF);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int d1=min(d[s1][i]+d[j][t1],d[s1][j]+d[i][t1]);
            int d2=min(d[s2][i]+d[j][t2],d[s2][j]+d[i][t2]);
            if(d1+d[i][j]<=l1 && d2+d[i][j]<=l2)
            mini=min(mini,d[i][j]+d1+d2);
        }
    }
    if(mini==INF)printf("-1\n");
    else printf("%d\n",m-mini);
    return 0;
}