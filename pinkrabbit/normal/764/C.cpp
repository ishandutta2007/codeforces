#include<cstdio>
#define ins(a,b) to[++s]=b,nxt[s]=h[a],h[a]=s
int n;
int e1[100000],e2[100000];
int h[100001],to[200001],nxt[200001],s;
int col[100001];
int vis[100001];
void init(){
	int x,y;
	scanf("%d",&n);
	s=0;
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		ins(x,y);
		ins(y,x);
		e1[i]=x,e2[i]=y;
	}
	for(int i=1;i<=n;++i) scanf("%d",col+i);
}
int dfs(int last,int c){
	for(int now=h[last];now;now=nxt[now]){
		if(!vis[to[now]]){
			if(col[to[now]]!=c)return 0;
			vis[to[now]]=1;
			if(!dfs(to[now],c)){
				vis[to[now]]=0;return 0;
			}
			vis[to[now]]=0;
		}
	}
	return 1;
}
int main(){
	init();
	int dc=0,ok=0,Ans;
	for(int i=1;i<n;++i){
		if(col[e1[i]]!=col[e2[i]]){
			dc=1;
			int ok2;
			//---
			vis[e1[i]]=1;
			ok2=1;
			for(int now=h[e1[i]];now;now=nxt[now]){
				vis[to[now]]=1;
				if(!dfs(to[now],col[to[now]])){
					ok2=0;vis[to[now]]=0;break;
				}
				vis[to[now]]=0;
			}
			vis[e1[i]]=0;
			if(ok2){
				ok=1;Ans=e1[i];break;
			}
			//----
			vis[e2[i]]=1;
			ok2=1;
			for(int now=h[e2[i]];now;now=nxt[now]){
				vis[to[now]]=1;
				if(!dfs(to[now],col[to[now]])){
					ok2=0;vis[to[now]]=0;break;
				}
				vis[to[now]]=0;
			}
			vis[e2[i]]=0;
			if(ok2){
				ok=1;Ans=e2[i];break;
			}
			//---
			break;
		}
	}
	if(dc){
		if(ok) printf("YES\n%d",Ans);
		else puts("NO");
	}
	else puts("YES\n1");
	return 0;
}