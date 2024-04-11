#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
int n,m,ans;
int h[100005],nxt[200005],to[200005],tot;
void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int vis[100005],cnt;
int stk[100005],top;
int que[100005],l,r;
int in[100005];
void DFS(int u){
	vis[u]=cnt; stk[++top]=u;
	for(int i=h[u];i;i=nxt[i]){
		if(!vis[to[i]]) DFS(to[i]);
		if(i&1) ++in[to[i]];
	}
}
int BFS(){
	l=1, r=0;
	F(i,1,top) if(in[stk[i]]==0) que[++r]=stk[i];
	while(l<=r){
		int u=que[l++];
		for(int i=h[u];i;i=nxt[i]) if(i&1)
			if(--in[to[i]]==0) que[++r]=to[i];
	}
	return r==top;
}
int main(){
	int x,y;
	scanf("%d%d",&n,&m); ans=n;
	F(i,1,m) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	F(i,1,n){
		if(!vis[i]){
			top=0;
			++cnt, DFS(i);
			ans-=BFS();
		}
	}
	printf("%d",ans);
	return 0;
}