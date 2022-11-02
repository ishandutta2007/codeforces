#include<stdio.h>
char in[5010][5010];
short xp[5010][5010],xn[5010][5010];
short yp[5010][5010],yn[5010][5010];
inline void del(int x,int y){
    xn[xp[x][y]][y]=xn[x][y];
    xp[xn[x][y]][y]=xp[x][y];
    yn[x][yp[x][y]]=yn[x][y];
    yp[x][yn[x][y]]=yp[x][y];
}
inline void add(int x,int y){
    xn[xp[x][y]][y]=x;
    xp[xn[x][y]][y]=x;
    yn[x][yp[x][y]]=y;
    yp[x][yn[x][y]]=y;
}
int n,m;
inline int go(int x,int y){
    if(x==0||y==0||x==n+1||y==m+1)return 0;
    del(x,y);
    int d;
    if(in[x][y]=='D')d=go(xn[x][y],y);
    else if(in[x][y]=='U')d=go(xp[x][y],y);
    else if(in[x][y]=='R')d=go(x,yn[x][y]);
    else if(in[x][y]=='L')d=go(x,yp[x][y]);
    add(x,y);
    return d+1;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%s",in[i]+1);
    for(i=1;i<=n;i++){
	int p=0;
	for(j=1;j<=m+1;j++){
	    if(in[i][j]!='.'){
		yn[i][p]=j;
		yp[i][j]=p;
		p=j;
	    }
	}
    }
    for(j=1;j<=m;j++){
	int p=0;
	for(i=1;i<=n+1;i++){
	    if(in[i][j]!='.'){
		xn[p][j]=i;
		xp[i][j]=p;
		p=i;
	    }
	}
    }
    int ans=0,ac=0;
    for(i=1;i<=n;i++){
	for(j=1;j<=m;j++){
	    if(in[i][j]!='.'){
		int d=go(i,j);
		if(d>ans){
		    ans=d;ac=1;
		}else if(d==ans)ac++;
	    }
	}
    }
    printf("%d %d\n",ans,ac);
}