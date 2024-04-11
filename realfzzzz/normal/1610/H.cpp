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
int n,m,fa[maxn],x[maxn],y[maxn];
vector<int> g[maxn];
int size[maxn],cnt=0,pos[maxn],dep[maxn];
void dfs(int u){
	pos[u]=++cnt;
	size[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int v:g[u]){
		dfs(v);
		size[u]+=size[v];
	}
}
int c[maxn];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
int query(int l,int r){
	return query(r)-query(l-1);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=2;i<=n;i++) g[fa[i]=readint()].push_back(i);
	dfs(1);
	for(int i=1;i<=m;i++){
		x[i]=readint();
		y[i]=readint();
		if(dep[x[i]]>dep[y[i]]) swap(x[i],y[i]);
		if(fa[y[i]]==x[i]){
			printf("-1\n");
			return 0;
		}
	}
	vector<int> vec;
	for(int i=1;i<=m;i++)
		if(pos[y[i]]>pos[x[i]]&&pos[y[i]]<pos[x[i]]+size[x[i]]) vec.push_back(i);
	sort(vec.begin(),vec.end(),[](int a,int b){
		return dep[x[a]]>dep[x[b]];
	});
	int ans=0;
	for(int i:vec){
		int u=*--upper_bound(g[x[i]].begin(),g[x[i]].end(),y[i],[](int a,int b){
			return pos[a]<pos[b];
		});
		if(query(pos[u],pos[u]+size[u]-1)>query(pos[y[i]],pos[y[i]]+size[y[i]]-1)) continue;
		ans++;
		modify(pos[u],1);
	}
	for(int i=1;i<=m;i++)
		if((pos[y[i]]<pos[x[i]]||pos[y[i]]>=pos[x[i]]+size[x[i]])&&query(pos[x[i]],pos[x[i]]+size[x[i]]-1)+query(pos[y[i]],pos[y[i]]+size[y[i]]-1)==ans){
			ans++;
			break;
		}
	printf("%d\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}