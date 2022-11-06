#include <cstdio>

char map[501][501];
bool vis[501][501];
int tx,ty;
int n,m;
int qx[501*501];
int qy[501*501];
int qp[501*501];

bool bfs(int a,int b){
    int head=1, tail=0;
    qx[0]=a; qy[0]=b;
    int cx,cy,nx,ny,dir;
    int dif[5]={0,1,0,-1,0};
    vis[a][b]=true;
    bool flg=false;
    while(tail<head){
        cx=qx[tail]; cy=qy[tail]; ++tail;
        if(cx==tx && cy==ty) {
            flg=true;
            break;
        }
        for(dir=0;dir<4;++dir){
            nx=cx+dif[dir]; ny=cy+dif[dir+1];
            if(0<=nx && 0<=ny && nx<n && ny<m){
                if(!vis[nx][ny] && map[nx][ny]=='.'){
                    vis[nx][ny]=true;
                    qp[head]=tail-1;
                    qx[head]=nx; qy[head]=ny; ++head;
                }
            }
        }
    }
    if(!flg) return false;
    --tail;
    while(tail>=0){
        map[qx[tail]][qy[tail]]='X';
        if(tail==0) break;
        tail=qp[tail];
    }
    return true;
}

bool chk(int a,int b){
    if(a<0 || b<0 || a>=n || b>=m) return false;
    return map[a][b]=='.';
}

bool adj(int a,int b){
    return
        chk(a-1,b)|| chk(a+1,b)||
        chk(a,b-1)|| chk(a,b+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(a=0;a<n;++a) scanf("%s",map[a]);
    scanf("%d%d",&a,&b);
    scanf("%d%d",&tx,&ty);
    --a; --b; --tx; --ty;
    char tmp=map[tx][ty]; map[tx][ty]='.';
    bool pathExist=bfs(a,b);
    map[tx][ty]=tmp;
    int i,j;
    if(pathExist && (((a!=tx || b!=ty) && map[tx][ty]=='X') || adj(tx,ty))) puts("YES");
    else puts("NO");
    return 0;
}