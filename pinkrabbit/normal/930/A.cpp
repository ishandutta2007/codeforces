#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int n,ans;
int cnt[100001]={1},dep[100001];
int h[100001],nxt[100001],to[100001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
void DFS(int u){
	eF(i,u){
		dep[to[i]]=dep[u]+1;
		++cnt[dep[u]+1];
		DFS(to[i]);
	}
}
int main(){
	scanf("%d",&n);
	int x;
	F(i,2,n) scanf("%d",&x), ins(x,i);
	DFS(1);
	F(i,0,n) ans+=(cnt[i]&1);
	printf("%d",ans);
	return 0;
}