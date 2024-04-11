#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
char in[60][60];
int n,m;
int vis[60][60];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
inline void dfs(int x,int y){
    if(vis[x][y])return;
    vis[x][y]=1;
    int i;
    for(i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&in[xx][yy]=='#')dfs(xx,yy);
    }
}
inline bool con(){
    memset(vis,0,sizeof(vis));
    int i,j,c=0;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(in[i][j]=='#'&&!vis[i][j]){
        if(c)return 0;
        c++;
        dfs(i,j);
    }
    return 1;
}
inline int solve(){
    int i,j,c=0;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(in[i][j]=='#')c++;
    if(c==1||c==2)return -1;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(in[i][j]=='#'){
        in[i][j]='.';
        if(!con())return 1;
        in[i][j]='#';
    }
    return 2;
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",in[i]);
    printf("%d\n",solve());
}