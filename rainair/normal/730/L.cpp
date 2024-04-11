#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
const int MAX = 250000+ 2;
const int MAXM = 18;
const int ha = 1e9 + 7;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n&1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

char str[MAXN];
int n,q,sm[MAXN],smd[MAXN];
std::vector<int> vec1[MAXN],vec2[MAXN],G[MAXN];
int L[MAXN],R[MAXN],tot;
int opt[MAXN],at[MAXN],rt,to[MAXN];
LL now[MAXN];
//0: +,1: *

// find opt[i] == '+', sm[i] = sm[l-1] any pos
// then opt[i] == '*', lower bound is ok

inline int build(int l,int r){
	if(smd[r] == smd[l-1]){
		int v = ++tot;
		L[v] = l;R[v] = r;
		FOR(i,l,r) at[i] = v;
		return v;
	}
	if(to[r] == l) return build(l+1,r-1);
	int t = sm[l-1]+MAX;
	int p = std::lower_bound(all(vec1[t]),l)-vec1[t].begin();
	if(p >= 0 && p < SZ(vec1[t]) && vec1[t][p] <= r){
		int v = ++tot;opt[v] = 0;
		G[v].pb(build(l,vec1[t][p]-1));
		G[v].pb(build(vec1[t][p]+1,r));
		return v;
	}
	p = std::lower_bound(all(vec2[t]),l)-vec2[t].begin();
	if(p >= 0 && p < SZ(vec2[t]) && vec2[t][p] <= r){
		int v = ++tot;opt[v] = 1;
		G[v].pb(build(l,vec2[t][p]-1));
		G[v].pb(build(vec2[t][p]+1,r));
		return v;
	}
	assert(0);
}

int f[MAXN][MAXM+1],dep[MAXN];

inline void dfs0(int v){
	if(L[v]){
		FOR(i,L[v],R[v]) now[v] = (1ll*now[v]*10+str[i]-'0')%ha;
	}
	dep[v] = dep[f[v][0]] + 1;
	FOR(i,1,MAXM) f[v][i] = f[f[v][i-1]][i-1];
	for(auto x:G[v]){
		f[x][0] = v;
		dfs0(x);
	}
	if(!L[v]){
		if(opt[v] == 0) now[v] = (now[G[v][0]]+now[G[v][1]])%ha;
		else now[v] = 1ll*now[G[v][0]]*now[G[v][1]]%ha;
	}	
}

struct Node{
	int mul,add;
	Node(int mul=0,int add=0) : mul(mul),add(add) {}
	Node operator * (const Node &t) const {
		return Node(1ll*mul*t.mul%ha,(1ll*add*t.mul+t.add)%ha);
	}
}g[MAXN][MAXM+1][2];
// 1: left go 2: right go

inline void dfs1(int v){
	FOR(i,1,MAXM) FOR(c,0,1) g[v][i][c] = g[v][i-1][c]*g[f[v][i-1]][i-1][c];
	if(L[v]) return;
	FOR(i,0,1){
		int x = G[v][i];
		if(opt[v] == 0){
			g[x][0][i] = Node(1,now[G[v][i^1]]);
		}
		else{
			g[x][0][i] = Node(now[G[v][i^1]],0);
		}
		g[x][0][i^1] = Node(1,0);
		dfs1(x);
	}
}

inline int lca(int x,int y){
	if(dep[x] != dep[y]){
		if(dep[x] < dep[y]) std::swap(x,y);
		int d = dep[x]-dep[y];
		FOR(i,0,MAXM) if((d>>i)&1) x = f[x][i];
	}
	if(x == y) return x;
	ROF(i,MAXM,0){
		if(f[x][i] == f[y][i]) continue;
		x = f[x][i],y = f[y][i];
	}
	return f[x][0];
}

int nxt[MAXN],pre[MAXN];
int mn[MAXM+1][MAXN],pc[MAXN];

inline int chk(int l,int r){
	// check if [l,r] is a good bracket
	if(sm[r] != sm[l-1]) return 0;
	int c = pc[r-l+1];
	int t = std::min(mn[c][l],mn[c][r-(1<<c)+1]);
	return t-sm[l-1] >= 0;
}

int orz[MAXN];
int pw[MAXN];

inline int getnum(int l,int r){
	return (orz[r]-1ll*orz[l-1]*pw[r-l+1]%ha+ha)%ha;
}

inline int get(int o,int x,int d,int l,int r){
	// get number [l,r]
	int t = (orz[r]-1ll*orz[l-1]*pw[r-l+1]%ha+ha)%ha;
	Node res(1,0);
	ROF(i,MAXM,0) if((d>>i)&1) res = res*g[x][i][o],x = f[x][i];
	return (1ll*res.mul*t+res.add)%ha;
}

int st[MAXN],tp;

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
	pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 10ll*pw[i-1]%ha;
	scanf("%s",str+1);
	n = strlen(str+1);
	scanf("%d",&q);
	FOR(i,1,n) sm[i] = sm[i-1]+(str[i] == '(' ? 1 : (str[i]==')'?-1:0));
	FOR(i,1,n){
		if(str[i] == '+') vec1[sm[i]+MAX].pb(i);
		if(str[i] == '*') vec2[sm[i]+MAX].pb(i);
		smd[i] = smd[i-1]+!isdigit(str[i]);
		int x = isdigit(str[i])?(str[i]-'0') : 0;
		orz[i] = (10ll*orz[i-1]+x)%ha;
		mn[0][i] = sm[i];
		if(str[i] == '(' || str[i] == ')'){
			if(str[i] == '(') st[++tp] = i;
			else{
				to[i] = st[tp];--tp;
			}
		}
	}
	FOR(i,1,MAXM) for(int j = 1;j+(1<<(i-1)) <= n;++j) mn[i][j] = std::min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
	FOR(i,1,n) pre[i] = isdigit(str[i])?i:pre[i-1];
	ROF(i,n,1) nxt[i] = isdigit(str[i])?i:nxt[i+1];
	rt = build(1,n);dfs0(rt);
	/*
	FOR(i,1,tot){
		if(SZ(G[i])){
			printf("opt[%d] = %d: %d %d\n",i,opt[i],G[i][0],G[i][1]);
		}
		else{
			printf("now[%d] = %d\n",i,now[i]);
		}
	}*/
	dfs1(rt);
	FOR(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		if(str[l] == '+' || str[l] == '*' || str[r] == '+' || str[r] == '*'){
			puts("-1");
			continue;
		}
		if(!chk(l,r)){
			puts("-1");
			continue;
		}
		if(smd[pre[r]] == smd[nxt[l]-1]){
			printf("%d\n",getnum(nxt[l],pre[r]));
			continue;
		}
		int ll = nxt[l],rr = pre[r];
		int x = at[ll],y = at[rr],lc = lca(x,y);
		// (a[x]i+b[x]-b[l])/a[l]
		int t1 = get(0,x,dep[x]-dep[lc]-1,ll,R[x]),t2 = get(1,y,dep[y]-dep[lc]-1,L[y],rr);
		int ans = 0;
		if(opt[lc] == 0) ans = (t1+t2)%ha;
		else ans = 1ll*t1*t2%ha;
		printf("%d\n",ans);
	}
	return 0;
}