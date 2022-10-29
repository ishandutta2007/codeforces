#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=1e3+9;
const ll mod=998244353;
int deg[N],vis[N];
queue<int> q; 
vi g[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++,deg[v]++;
		g[u].pb(v),g[v].pb(u);
	}
	rep(i,1,n+1)if(deg[i]==1)q.push(i);
	n>>=1;
	int p;
	while(q.size()>1){
		int u=q.front();
		q.pop();
		int v=q.front();
		q.pop();
		printf("? %d %d\n",u,v);
		fflush(stdout);
		scanf("%d",&p);
		if(u==p||v==p){
			printf("! %d",p);
			fflush(stdout);
			return 0;
		}
		else{
			for(auto w:g[u]){
				--deg[w];
				if(deg[w]==1)q.push(w);
			}
			for(auto w:g[v]){
				--deg[w];
				if(deg[w]==1)q.push(w);
			}
		}
	}
	p=q.front();
	printf("! %d",p);
	fflush(stdout);
}