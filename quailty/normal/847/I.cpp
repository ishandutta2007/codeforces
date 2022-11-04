#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=255;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char str[MAXN][MAXN];
int n,m,p,q;
int res[MAXN][MAXN];
int cnt[MAXN][MAXN];
vector<pair<int,int> > vis;
void bfs(int x,int y)
{
    cnt[x][y]=(str[x][y]-'A'+1)*q;
    queue<pair<int,int> > que;
    que.push({x,y});
    while(!que.empty())
    {
        pair<int,int> tmp=que.front();
        que.pop();
        vis.push_back(tmp);
        int ux=tmp.first,uy=tmp.second;
        res[ux][uy]+=cnt[ux][uy];
        for(int i=0;i<4;i++)
        {
            int vx=ux+d[i][0],vy=uy+d[i][1];
            if(vx>=1 && vx<=n && vy>=1 && vy<=m && str[vx][vy]!='*'
            && cnt[vx][vy]<cnt[ux][uy]/2)
            {
                cnt[vx][vy]=cnt[ux][uy]/2;
                que.push({vx,vy});
            }
        }
    }
//    for(int i=1;i<=n;i++,printf("\n"))
//        for(int j=1;j<=m;j++)
//            printf("%d ",cnt[i][j]);
//    printf("\n");
    for(auto &t:vis)
        cnt[t.first][t.second]=0;
    vis.clear();
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&q,&p);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]>='A' && str[i][j]<='Z')
                bfs(i,j);
    int tot=0;
//    for(int i=1;i<=n;i++,printf("\n"))
//        for(int j=1;j<=m;j++)
//            printf("%d ",res[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tot+=(res[i][j]>p);
    printf("%d\n",tot);
    return 0;
}