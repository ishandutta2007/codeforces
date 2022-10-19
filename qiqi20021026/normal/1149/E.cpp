#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,a[N],x,y,tot,head[N],sg[N],vis[N],ans[N],tmp;
bool fl;
struct edge{int v,nxt;}e[N];

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

void dfs(int u){
	if (~sg[u]) return;
	vector<int> vec; vec.clear();
	for (int i=head[u],v;i;i=e[i].nxt){
		dfs(v=e[i].v);
		vec.push_back(sg[v]);
	}
	for (auto i:vec) vis[i]=u;
	for (sg[u]=0;vis[sg[u]]==u;++sg[u]);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	memset(sg,-1,sizeof sg);
	for (int i=1;i<=n;++i){dfs(i); ans[sg[i]]^=a[i];}
	for (int i=0;i<=n;++i) fl|=ans[i]>0;
	if (!fl){puts("LOSE"); return 0;}
	puts("WIN");
	for (int i=n;~i;--i) if (ans[i]){tmp=i; break;}
	for (int i=1;i<=n;++i)
		if (sg[i]==tmp){
			int t=ans[tmp]^a[i];
			if (t<a[i]){
				ans[tmp]=0; a[i]=t;
				for (int j=head[i];j;j=e[j].nxt){
					int v=e[j].v;
					a[v]=ans[sg[v]]^a[v];
					ans[sg[v]]=0;
				}
				break;
			}
		}
	for (int i=1;i<=n;++i) printf(i==n?"%d\n":"%d ",a[i]);
	
	return 0;
}