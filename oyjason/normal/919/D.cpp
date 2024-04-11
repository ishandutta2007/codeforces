#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 300020
using namespace std;
int read(){
	int num=0,oe=1;char cw=getchar();
	while(!isdigit(cw)) oe=cw=='-'?-1:1,cw=getchar();
	while(isdigit(cw)) num=num*10+cw-'0',cw=getchar();
	return num*oe;
}
void fad(){puts("-1");exit(0);}
int n,m,ans,f[M],nt[M<<1],to[M<<1],tmp,in[M];
int dp[M][26],a,b,q[M],hd,tl,now;
void link(int x,int y){nt[++tmp]=f[x],f[x]=tmp,to[tmp]=y;}
char ch[M];
bool vis[M];
int main(){
	n=read(),m=read(),memset(f,-1,sizeof(f));
	scanf("%s",ch+1),hd=tl=0,memset(vis,false,sizeof(vis));
	for(int i=1;i<=m;i++){
		a=read(),b=read();
		in[b]++,link(a,b);
    }
    for(int i=1;i<=n;i++){
    	if(in[i]==0) q[tl++]=i;
	}
	while(hd<tl){
		now=q[hd++],vis[now]=true;
		dp[now][ch[now]-'a']++;
		for(int k=0;k<26;k++) ans=max(ans,dp[now][k]);
		for(int i=f[now];i!=-1;i=nt[i]){
			if(--in[to[i]]==0) q[tl++]=to[i];
			for(int k=0;k<26;k++) dp[to[i]][k]=max(dp[to[i]][k],dp[now][k]);
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]) fad();
	printf("%d\n",ans);
	return 0;
}