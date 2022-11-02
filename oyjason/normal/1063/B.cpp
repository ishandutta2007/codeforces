#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 2020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,p[M][M][2],sx,sy,q[M*M*3],ans,hd,tl;
void ins(int x,int y,int kd){if(kd==1) q[tl++]=x*M+y;else q[--hd]=x*M+y;}
void tk(int &x,int &y){x=q[hd]/M,y=q[hd]%M,hd++;}
char ch[M][M];
int main(){
	memset(p,-1,sizeof(p)),n=read(),m=read(),sx=read(),sy=read();
	hd=tl=M*M+M*M/2;
	p[sx][sy][0]=read(),p[sx][sy][1]=read();
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1); ins(sx,sy,0);
	while(hd<tl){
		int x,y,d1,d2; tk(x,y),d1=p[x][y][0],d2=p[x][y][1];
		if(x>1&&ch[x-1][y]=='.'&&p[x-1][y][0]==-1){
			p[x-1][y][0]=d1,p[x-1][y][1]=d2,ins(x-1,y,0);
		}
		if(x<n&&ch[x+1][y]=='.'&&p[x+1][y][0]==-1){
			p[x+1][y][0]=d1,p[x+1][y][1]=d2,ins(x+1,y,0);
		}
		if(d1&&y>1&&ch[x][y-1]=='.'&&p[x][y-1][0]==-1){
			p[x][y-1][0]=d1-1,p[x][y-1][1]=d2,ins(x,y-1,1);
		}
		if(d2&&y<m&&ch[x][y+1]=='.'&&p[x][y+1][0]==-1){
			p[x][y+1][0]=d1,p[x][y+1][1]=d2-1,ins(x,y+1,1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(p[i][j][0]!=-1) ans++;
	}
	printf("%d\n",ans);
	return 0;
}