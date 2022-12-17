#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,m,q,a[maxn],b[maxn];
vector<int> g[maxn];
bool vis[maxn];
int fa[maxn],dep[maxn];
void dfs(int u){
	vis[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int v:g[u]) if(!vis[v]){
		fa[v]=u;
		dfs(v);
	}
}
int c[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=0;i<m;i++){
		int x,y;
		x=readint();
		y=readint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	q=readint();
	for(int i=1;i<=q;i++){
		a[i]=readint();
		b[i]=readint();
		c[a[i]]++;
		c[b[i]]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=c[i]%2;
	if(!cnt){
		printf("YES\n");
		for(int i=1;i<=q;i++){
			vector<int> res1,res2;
			int x=a[i],y=b[i];
			while(x!=y)
				if(dep[x]>dep[y]){
					res1.push_back(x);
					x=fa[x];
				}
				else{
					res2.push_back(y);
					y=fa[y];
				}
			reverse(res2.begin(),res2.end());
			printf("%d\n",(int)res1.size()+(int)res2.size()+1);
			for(int i:res1) printf("%d ",i);
			printf("%d ",x);
			for(int i:res2) printf("%d ",i);
			printf("\n");
		}
	}
	else printf("NO\n%d\n",(cnt+1)/2);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}