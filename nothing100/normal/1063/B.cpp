#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,m,r,c,x,y,inque[2020][2020],ans,vis[2020][2020];
pair<int,int> num[2020][2020];
char ch[2020][2020];
queue<pair<int,int> >q;
bool canReach(int x1,int y1){
    if (x1>=0&&x1<n&&y1>=0&&y1<m&&ch[x1][y1]=='.') return true;
    return false;
}
void update(int x1,int y1,int a,int b){
    if (canReach(x1,y1)&&num[x1][y1].fi<a){
        num[x1][y1].fi=a;
        num[x1][y1].se=b;
        if (!inque[x1][y1]){
            q.push(make_pair(x1,y1));
            inque[x1][y1]=1;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&r,&c);
    r--;c--;
    scanf("%d%d",&x,&y);
    for (int i=0;i<n;i++) scanf("%s",ch[i]);
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++) num[i][j].fi=-1;
    num[r][c]=make_pair(x,y);
    q.push(make_pair(r,c));
    inque[r][c]=1;
    while (!q.empty()){
        pair<int,int> now=q.front();
        q.pop();
        vis[now.fi][now.se]=1;
        inque[now.fi][now.se]=0;
        update(now.fi-1,now.se,num[now.fi][now.se].fi,num[now.fi][now.se].se);
        update(now.fi+1,now.se,num[now.fi][now.se].fi,num[now.fi][now.se].se);
        if (num[now.fi][now.se].fi>0) update(now.fi,now.se-1,num[now.fi][now.se].fi-1,num[now.fi][now.se].se);
        if (num[now.fi][now.se].se>0) update(now.fi,now.se+1,num[now.fi][now.se].fi,num[now.fi][now.se].se-1);
    }
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
    if (vis[i][j]) ans++;
    printf("%d\n",ans);
}