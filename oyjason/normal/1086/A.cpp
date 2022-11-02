#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,px[200],py[200],tx[200],ty[200],X,Y;
int vis[1009][1009];
void pt(int x,int y){
	while(true){
		if(!vis[x][y]) vis[x][y]=1,m++;
		if(x==X&&y==Y) return;
		if(x>X) x--; else if(x<X) x++;
		else if(y<Y) y++; else if(y>Y) y--;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i=1;i<=3;i++) px[i]=read(),py[i]=read(),tx[i]=px[i],ty[i]=py[i];
	sort(tx+1,tx+4),sort(ty+1,ty+4); X=tx[2],Y=ty[2];
	for(int i=1;i<=3;i++) pt(px[i],py[i]);
	printf("%d\n",m);
	for(int i=0;i<1001;i++) for(int j=0;j<1001;j++) if(vis[i][j]) printf("%d %d\n",i,j);
	return 0;
}