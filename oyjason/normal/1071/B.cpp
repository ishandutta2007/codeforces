#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define LL long long
#define M 2010
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
char ch[M][M];
int n,m,F[M][M],ans,od[M][M],S[2*M*M][2],top[2];
void ins(int kd,int x,int y){S[++top[kd]][kd]=x*M+y;}
void bfs(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+j-1==ans&&i+j-1-F[i][j]<=m) ins(0,i,j);
		}
	}
	if(!ans) ins(0,1,1);
	for(int nw=0;true;nw^=1){
		top[nw^1]=0;
		for(int k=0;k<26;k++){
			bool fg=false;
			for(int i=1;i<=top[nw];i++){
				int x=S[i][nw]/M,y=S[i][nw]%M;
				if(x==n&&y==n) return ;
				if(x<n&&ch[x+1][y]==k+'a'&&!od[x+1][y]) ins(nw^1,x+1,y),fg=true,od[x+1][y]=1;
				if(y<n&&ch[x][y+1]==k+'a'&&!od[x][y+1]) ins(nw^1,x,y+1),fg=true,od[x][y+1]=2;
			}
			if(fg) break;
		}
	}
}
void opt(int x,int y){
	if(x+y-1==ans){for(int i=1;i<x+y;i++) putchar('a');return;}
	if(y==1&&x==1){putchar(ch[x][y]);return;}
	if(od[x][y]==1) opt(x-1,y);else opt(x,y-1); putchar(ch[x][y]);
}
int main(){
	n=read(),m=read(),m=min(m,(n<<1)-1);
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		for(int j=1;j<=n;j++){
			F[i][j]=max(F[i-1][j],F[i][j-1])+(ch[i][j]=='a');
			if(i+j-1-F[i][j]<=m&&ans<i+j-1) ans=i+j-1;
		}
	} bfs(),opt(n,n),putchar('\n'); return 0;
}