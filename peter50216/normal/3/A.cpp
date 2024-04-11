#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int dis[10][10];
int pre[10][10];
queue<pair<int,int> > q;
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
char na[8][3]={"RD","R","RU","U","LU","L","LD","D"};
int main(){
    char a[4],b[4];
    scanf("%s%s",&a,&b);
    int ax=a[0]-'a',bx=b[0]-'a',ay=a[1]-'1',by=b[1]-'1';
    dis[bx][by]=1;
    pre[bx][by]=-1;
    q.push(make_pair(bx,by));
    while(!q.empty()){
	int nx=q.front().first,ny=q.front().second;
	//printf("%d %d\n",nx,ny);
	q.pop();
	for(int i=0;i<8;i++){
	    int xx=nx-dx[i],yy=ny-dy[i];
	    if(xx>=0&&xx<8&&yy>=0&&yy<8&&dis[xx][yy]==0){
		dis[xx][yy]=dis[nx][ny]+1;
		pre[xx][yy]=i;
		q.push(make_pair(xx,yy));
	    }
	}
    }
    printf("%d\n",dis[ax][ay]-1);
    while(pre[ax][ay]!=-1){
	puts(na[pre[ax][ay]]);
	int xx=ax;
	ax+=dx[pre[xx][ay]];
	ay+=dy[pre[xx][ay]];
    }
}