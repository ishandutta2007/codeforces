#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#define For(i,a,b) for(int i=a;i<=(int)(b);++i)
#define Ford(i,a,b) for(int i=a;i>=(int)(b);--i)
#define For2(i,a,b) for(int i=a;i<(int)(b);++i)
#define Ford2(i,a,b) for(int i=a;i>(int)(b);--i)
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int n;
int fk[31][31];
int e[31]={0};
int b[31],dir[31][4];
int x[31],y[31];
void init(){
	scanf("%d",&n);
	For(i,1,n){
		e[i]=0;
		b[i]=0;
		dir[i][0]=dir[i][1]=dir[i][2]=dir[i][3]=0;
	}
	For(i,1,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		fk[a][b]=fk[b][a]=1;
		++e[a];
		++e[b];
	}
}
void dfs(int k,int dis){
	For(i,1,n){
		if(fk[k][i]&&!b[i]){
			b[i]=1;
			int d=-1;
			while(dir[k][++d]);
			x[i]=x[k]+dis*dx[d];
			y[i]=y[k]+dis*dy[d];
			dir[k][d]=1;
			dir[i][d^1]=1;
			dfs(i,dis/2);
		}
	}
}
int main(){
	init();
	For(i,1,n){
		if(e[i]>4){
			puts("NO");
			return 0;
		}
	}
	x[1]=0;y[1]=0;
	b[1]=1;
	dfs(1,1<<(n-2));
	puts("YES");
	For(i,1,n){
		printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}