#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int map[2010][2010];
int vis[2010][2010];
int minx,maxx,miny,maxy;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n;
inline void dfs(int x,int y){
    vis[x][y]=1;
    minx=min(x,minx);
    miny=min(y,miny);
    maxx=max(x,maxx);
    maxy=max(y,maxy);
    int i;
    for(i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<n&&map[xx][yy]&&!vis[xx][yy])dfs(xx,yy);
    }
}
inline bool isc(){
    int w=maxx-minx+1,h=maxy-miny+1;
    if(map[minx+3][miny+h/2]&&map[minx+w/2][miny+3]&&map[maxx-3][miny+h/2]&&map[minx+w/2][maxy-3]){
        int dw=w*0.18,dh=h*0.18;
        if(map[minx+dw][miny+dh]&&map[minx+dw][maxy-dh]&&map[maxx-dw][miny+dh]&&map[maxx-dw][maxy-dh]){
            dw=w*0.09,dh=h*0.09;
            if(!map[minx+dw][miny+dh]&&!map[minx+dw][maxy-dh]&&!map[maxx-dw][miny+dh]&&!map[maxx-dw][maxy-dh]){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<n;j++){
        scanf("%d",&map[i][j]);
    }
    int c=0,s=0;
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(map[i][j]&&vis[i][j]==0){
        minx=miny=10000;
        maxx=maxy=-10000;
        dfs(i,j);
        if(isc())c++;
        else s++;
    }
    printf("%d %d\n",c,s);
}