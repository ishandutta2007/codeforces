#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 
const int N=1e6+5;
int n,q,cand[N][2];
char s[N];
int dep[N],fa[N];
VI e[N];
char ans[N];
struct ask {
	int u,v;
	string s;
}as[N];

namespace SAT2 {
	static const int M=6400000;
	VI e[M];
	int tot,top,stk[M];
	bool mark[M];
	void add(int u,int v) {e[u].pb(v);}
	void add_edge(int u,int us,int v,int vs) {
		// printf("add %d %d %d %d\n",u,us,v-n,vs);
		add(2*u+us,2*v+vs);
		add(2*v+!vs,2*u+!us);
	}
	bool dfs(int x) {
		if (mark[x]) return true;
		if (mark[x^1]) return false;
		mark[stk[++top]=x]=true;
		for (auto y:e[x]) if (!dfs(y)) return false;
		return true;
	}
	bool solve() {
		tot=n+q;
		rep(i,1,tot+1) if (!mark[2*i]&&!mark[2*i+1]) {
			top=0;
			if (!dfs(2*i)) {
				while (top) mark[stk[top--]]=false;
				if (!dfs(2*i+1)) return false;
			}
		}
		return true;
	}
}

void dfs(int u,int f) {
	fa[u]=f;
	dep[u]=dep[f]+1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);	
	}
}
VI getway(int u,int v,int l) {
	VI q1,q2;
	// while (u!=v) {
	// 	if (dep[u]>dep[v]) q1.pb(u),u=fa[u];
	// 	else q2.pb(v),v=fa[v];
	// }
	// int pu=(dep[u]-dep[v]+l)/2,pv=(dep[v]-dep[u]+l)/2;
	int pu=(dep[u]-dep[v]+l)/2;
	int pv=(dep[v]-dep[u]+l)/2;
	rep(j,0,pu) {
		q1.pb(u); u=fa[u];
	}
	
	// for (int j=0;j<pv;j++) {
	// 	q2.pb(v); v=fa[v];
	// }
	rep(j,0,pv) {
		q2.pb(v); v=fa[v];
	}
	
	q1.push_back(u);
	reverse(all(q2));
	for (auto e:q2) q1.pb(e);
	return q1;
}

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);
	}	
	dfs(1,0);
	// [1,n] 
	rep(i,1,n+1) cand[i][0]=cand[1][0]='a';
	rep(i,1,q+1) {
		int u,v,l;
		scanf("%d%d%s",&u,&v,s); l=strlen(s); 
		as[i]={u,v,s};
		VI w=getway(u,v,l);
		rep(j,0,l) {
			cand[w[j]][0]=s[j];
			cand[w[j]][1]=s[l-1-j];
		}
	}
	/*
	rep(i,1,n+1) rep(j,0,2) {
		printf("cand[%d][%d]=%c ",i,j,cand[i][j]);
		if (j==1) puts("");
	}
	*/
	rep(i,1,q+1) {
		int l=as[i].s.length();
		VI w=getway(as[i].u,as[i].v,l);
		
		rep(j,0,l) rep(k,0,2) {
			// edge(node,query)
			if (cand[w[j]][k]!=as[i].s[j]) SAT2::add_edge(w[j],k,n+i,1);
			if (cand[w[j]][k]!=as[i].s[l-1-j]) SAT2::add_edge(w[j],k,n+i,0);
		}
	}
	if (!SAT2::solve()) {
		puts("NO");
	}else {
		puts("YES");
		rep(i,1,n+1) ans[i]='a'; ans[n+1]='\0';
		rep(i,1,n+1) {
			if (SAT2::mark[2*i]) ans[i]=cand[i][0];
			else ans[i]=cand[i][1];
		}
		puts(ans+1);
	}
	return 0;	
}