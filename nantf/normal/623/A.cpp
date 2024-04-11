#include<bits/stdc++.h>
using namespace std;
const int maxn=555;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,el,head[maxn],to[maxn*maxn],nxt[maxn*maxn],dep[maxn],cnt;
bool e[maxn][maxn],flag=true;
char ans[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	dep[u]=dep[f]^1;cnt++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(dep[v]!=-1){
			if(dep[v]!=(dep[u]^1)) flag=false;
			continue;
		}
		dfs(v,u);
	}
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		e[u][v]=e[v][u]=true;
	}
	FOR(i,1,n) FOR(j,i+1,n) if(!e[i][j]) add(i,j),add(j,i);
	MEM(dep,-1);
	dep[0]=0;
	FOR(i,1,n) if(dep[i]==-1){
		cnt=0;
		dfs(i,0);
		if(cnt==1) dep[i]=-1;
	}
	if(!flag) return puts("No"),0;
	FOR(i,1,n){
		if(dep[i]==1) ans[i]='a';
		if(dep[i]==0) ans[i]='c';
		if(dep[i]==-1) ans[i]='b';
	}
	FOR(i,1,n) FOR(j,i+1,n) if(ans[i]=='a' && ans[j]=='c' || ans[i]=='c' && ans[j]=='a'){
		if(e[i][j]) return puts("No"),0;
	}
	else{
		if(!e[i][j]) return puts("No"),0;
	}
	puts("Yes");
	FOR(i,1,n) putchar(ans[i]);
}