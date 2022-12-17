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
int n;
vector<int> g[maxn];
int fa[maxn],f[maxn];
void dfs(int u){
	for(int v:g[u]) if(v!=fa[u]){
		fa[v]=u;
		dfs(v);
		f[u]^=f[v]+1;
	}
}
bool t[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<n;i++){
		int x,y;
		x=readint();
		y=readint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	int cnt=0,res=f[1];
	t[1]=1;
	printf(res?"1":"2");
	for(int i=2;i<=n;i++){
		if(!t[i]){
			res^=f[i];
			int u=i;
			while(!t[fa[u]]){
				t[u]=1;
				res^=f[fa[u]]^(f[u]+1);
				cnt++;
				u=fa[u];
			}
			t[u]=1;
			cnt++;
			res^=f[u]+1;
		}
		printf(res^(cnt&1)?"1":"2");
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}