#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,m,tot=0,now=1;
int v[2000005],next[2000005],h1[1000005],h2[1000005];
bool vis[1000005],choose[1000005];

inline void addedge1(int x,int y){v[++tot]=y; next[tot]=h1[x]; h1[x]=tot;}
inline void addedge2(int x,int y){v[++tot]=y; next[tot]=h2[x]; h2[x]=tot;}

inline void work(){
	while(now<=n&&vis[now])
		now++;
	if(now==n+1)
		return;
	int u=now++;
	for(int p=h1[u];p;p=next[p])
		vis[v[p]]=true;
	choose[u]=true;
	work();
	for(int p=h2[u];p;p=next[p])
		if(choose[v[p]])
			choose[u]=false;
}

inline int readint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		addedge1(x,y);
		addedge2(y,x);
	}
	work();
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(choose[i])
			cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		if(choose[i])
			printf("%d ",i);
	printf("\n");
	return 0;
}