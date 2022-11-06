#include <cstdio>

char map[52][52];
bool vis[52][52];
int n,m;

int d[5]={0,1,0,-1,0};

char targ;

int px[52][52];
int py[52][52];

bool hasCycle(int xx,int yy){
    if(vis[xx][yy]) {
        //printf("Cycle %d %d\n",xx,yy);
        return true;
    }
    vis[xx][yy]=true;
    int nx,ny,dir;
    for(dir=0;dir<4;++dir){
        nx=xx+d[dir]; ny=yy+d[dir+1];
        if(0<=nx && 0<=ny && nx<n && ny<m){
            if(map[nx][ny]==targ){
                if(px[xx][yy]==nx && py[xx][yy]==ny) continue;
                px[nx][ny]=xx;
                py[nx][ny]=yy;
                if(hasCycle(nx,ny)) return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<n;++i) scanf("%s",map[i]);
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            if(!vis[i][j]){
                targ=map[i][j];
                if(hasCycle(i,j)){
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    puts("No");
    return 0;
}