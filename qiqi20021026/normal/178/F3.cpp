#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 2200
#define M N*500

int n,m,xb,tot,len,sss,sum[M],head[M],deep[M],top[M],t[M][30],size[M],f[N*2][N];
char s[N];
struct edge{int v,len,nxt;}e[M*2];

void add(int x,int y,int z){e[++tot].v=y; e[tot].len=z; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int x,int fa,int tt){
	top[x]=tt; deep[x]=deep[fa]+1;
	int flag=0;
	for (int i=1;i<=26;i++) if (t[x][i]) flag++;
	if (flag==0){add(top[x],x,deep[x]-deep[top[x]]); return;}
	if (flag>1 || sum[x]!=0){flag=2; add(top[x],x,deep[x]-deep[top[x]]);}
	for (int i=1;i<=26;i++)
		if (t[x][i])
			if (flag==1) dfs(t[x][i],x,top[x]); else dfs(t[x][i],x,x);
}

int C(int x){return x*(x-1)/2;}

int dp(int u,int fa,int len){
	int ret=++sss;
	size[u]=sum[u];
	for (int i=size[u];i>=1;i--) f[ret][i]=len*C(i);
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa && v!=u){
			int tmp=dp(v,u,e[i].len); size[u]+=size[v];
			for (int j=size[u];j>=1;j--)
				for (int k=1;k<=size[v] && k<=j;k++)
					f[ret][j]=max(f[ret][j],f[ret][j-k]+f[tmp][k]+len*(j-k)*k+len*C(k));
		}
	return ret;
}

int main(){
	scanf("%d%d",&n,&m); xb=1;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		int w=1; int len=strlen(s+1);
		for (int j=1;j<=len;j++)
			if (!t[w][s[j]-'a'+1]) w=t[w][s[j]-'a'+1]=++xb;
			else w=t[w][s[j]-'a'+1];
		sum[w]++;
	}
	dfs(1,0,1); dp(1,0,0);
	printf("%d\n",f[1][m]);
	return 0;
}