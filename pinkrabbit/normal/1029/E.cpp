#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;

int n,Ans;

int h[200001],nxt[400001],to[400001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int f[200001],d[200001];

void DFS(int u,int fa){
	f[u]=fa;eF(i,u) if(to[i]!=fa){d[to[i]]=d[u]+1; DFS(to[i],u);}
}

priority_queue<pii>q;
bool vis[200001];

int main(){
	int x,y;
	scanf("%d",&n);
	F(i,2,n) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS(1,0);
	F(i,1,n) q.push(pii(d[i],i));
	int Ans=0;
	while(!q.empty()) {
		while(!q.empty()&&vis[q.top().second])q.pop();
		if(q.empty())break;
		if(q.top().first<3)break;
		Ans++;int u=q.top().second;
		vis[f[u]]=1;
		eF(i,f[u])vis[to[i]]=1;
	}
	printf("%d\n",Ans);
	return 0;
}