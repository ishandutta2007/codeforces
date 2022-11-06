#include <cstdio>
#define myapply(a,b) map[px][py]=a, map[nx][ny]=b

char map[2010][2010];
int  deg[2010][2010];
int n,m;

bool bound(int x,int y) { return 0<=x && 0<=y && x<n && y<m; }

int qx[2010*2010];
int qy[2010*2010];

int dif[5]={0,1,0,-1,0};

void fill(int px,int py,int nx,int ny,int d) {
         if(d==0) myapply('<','>');
    else if(d==1) myapply('^','v');
    else if(d==2) myapply('>','<');
    else if(d==3) myapply('v','^');
}

void applyDeg(int x,int y){
    int nx,ny;
    for(int i=0;i<4;++i){
        nx=x+dif[i]; ny=y+dif[i+1];
        if(bound(nx,ny)) --deg[nx][ny];
    }
}

void work(int px,int py){
    int head=1, tail=0;
    qx[tail]=px; qy[tail]=py;
    int cx,cy,nx,ny,dir;
    while(tail<head){
        cx=qx[tail]; cy=qy[tail]; ++tail;
        for(dir=0;dir<4;++dir){
            nx=cx+dif[dir]; ny=cy+dif[dir+1];
            if(bound(nx,ny) && map[nx][ny]=='.') break;
        }
        fill(cx,cy,nx,ny,dir);
        applyDeg(cx,cy); applyDeg(nx,ny);
        cx=nx; cy=ny;
        for(dir=0;dir<4;++dir){
            nx=cx+dif[dir]; ny=cy+dif[dir+1];
            if(bound(nx,ny) && map[nx][ny]=='.' && deg[nx][ny]==1) {
                qx[head]=nx; qy[head]=ny; ++head;
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    int i,j;
    for(i=0;i<n;getchar(),++i)for(j=0;j<m;++j){
        map[i][j]=getchar();
    }
    int d;
    int nx,ny;
    int cnt;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            cnt=0;
            for(d=0;d<4;++d){
                nx=i+dif[d];
                ny=j+dif[d+1];
                if(bound(nx,ny) && map[nx][ny]=='.') ++cnt;
            }
            deg[i][j]=cnt;
        }
    }
    for(i=0;i<n;++i) for(j=0;j<m;++j) if(map[i][j]=='.' && deg[i][j]==1) work(i,j);
    for(i=0;i<n;++i) for(j=0;j<m;++j){
        if(map[i][j]=='.'){
            puts("Not unique");
            return 0;
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            putchar(map[i][j]);
        }
        putchar(10);
    }
    return 0;
}