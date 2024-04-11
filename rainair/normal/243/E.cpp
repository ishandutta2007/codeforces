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

const int MAXN = 1e5 + 5;

int typ[MAXN],col[MAXN];
std::vector<int> G[MAXN];
int bin[MAXN],tp,tot;
int n,m;

inline void run(){
	puts("NO");
	exit(0);
}

inline int New(int o){
	int v = tp ? bin[tp--] : ++tot;
	typ[v] = o;return v;
}

inline void del(int v){
	G[v].clear();bin[++tp] = v;
}

inline bool chk(std::vector<int> &vec){
	int ps = -1;
	FOR(i,0,SZ(vec)-1) if(col[vec[i]] == 2){
		if(ps != -1) return 0;
		ps = i;
	}
	if(ps == -1){
		FOR(i,0,SZ(vec)-1) if(col[vec[i]]){ps = i;break;}
	}
	FOR(i,0,ps-1) if(col[vec[i]] != 0) return 0;
	FOR(i,ps+1,SZ(vec)-1) if(col[vec[i]] != 1) return 0;
	return 1;
}

inline std::vector<int> split(int v){// 01
	if(col[v] <= 1) return {v};
	if(typ[v]){// Q
		if(!chk(G[v])) std::reverse(all(G[v]));
		if(!chk(G[v])) run();
		std::vector<int> res;
		for(auto x:G[v]){
			if(col[x] != 2) res.pb(x);
			else{
				std::vector<int> tmp = split(x);
				res.insert(res.end(),all(tmp));
			}
		}
		del(v);
		return res;
	}
	else{// P
		std::vector<int> son[3];
		for(auto x:G[v]) son[col[x]].pb(x);
		if(SZ(son[2]) > 1) run();
		std::vector<int> res;
		if(SZ(son[0])){
			int n0 = New(0);G[n0] = son[0];
			res.pb(n0);
		}
		if(SZ(son[2])){
			std::vector<int> tmp = split(son[2][0]);
			res.insert(res.end(),all(tmp));
		}
		if(SZ(son[1])){
			int n1 = New(0);G[n1] = son[1];
			res.pb(n1);
		}
		del(v);
		return res;
	}
}

inline void work(int v){
	if(col[v] <= 1) return;
	if(typ[v]){// Q
		int l = 1e9,r = -1e9;
		FOR(i,0,SZ(G[v])-1) if(col[G[v][i]]) l = std::min(l,i),r = std::max(r,i);
		FOR(i,l+1,r-1) if(col[G[v][i]] != 1) run();
		if(l == r && col[G[v][l]] == 2){
			work(G[v][l]);
			return;
		}
		std::vector<int> son;
		FOR(i,0,l-1) son.pb(G[v][i]);
		if(col[G[v][l]] == 2){
			std::vector<int> tmp = split(G[v][l]);
			son.insert(son.end(),all(tmp));
		}
		else son.pb(G[v][l]);
		FOR(i,l+1,r-1) son.pb(G[v][i]);
		if(l != r){
			if(col[G[v][r]] == 2){
				std::vector<int> tmp = split(G[v][r]);
				std::reverse(all(tmp));
				son.insert(son.end(),all(tmp));
			}
			else son.pb(G[v][r]);
		}
		FOR(i,r+1,SZ(G[v])-1) son.pb(G[v][i]);
		G[v] = son;
	}
	else{// P
		std::vector<int> son[3];
		for(auto x:G[v]) son[col[x]].pb(x);
		if(son[1].empty() && SZ(son[2]) == 1){
			work(son[2][0]);
			return;
		}
		G[v].clear();
		if(SZ(son[2]) > 2) run();
		G[v] = son[0];
		int n1 = New(1);G[v].pb(n1);
		if(SZ(son[2]) >= 1){
			std::vector<int> tmp = split(son[2][0]);
			G[n1].insert(G[n1].end(),all(tmp));
		}

		if(SZ(son[1])){
			int n2 = New(0);
			G[n1].pb(n2);
			G[n2] = son[1];
		}

		if(SZ(son[2]) >= 2){
			std::vector<int> tmp = split(son[2][1]);
			std::reverse(all(tmp));
			G[n1].insert(G[n1].end(),all(tmp));
		}
	}
}

char str[MAXN];

inline void apply(int v){
	if(v >= 2 && v <= m+1){
		col[v] = (str[v-1]=='1');
		return;
	}
	int c0 = 0,c1 = 0;
	for(auto x:G[v]){
		apply(x);
		if(col[x] == 0) c0 = 1;
		else if(col[x] == 1) c1 = 1;
		else c0 = c1 = 1;
	}
	if(c0 && !c1) col[v] = 0;
	else if(!c0 && c1) col[v] = 1;
	else col[v] = 2;
}

inline void gao(int v){
	for(auto &x:G[v]){
		int t = x;
		while(SZ(G[t]) == 1){
			int p = t;
			t = G[t][0];
			del(p);
		}
		x = t;gao(x);
	}
}

std::vector<int> ans;

inline void dfs(int v){
	if(v >= 2 && v <= m+1){
		ans.pb(v-1);
		return;
	}
	for(auto x:G[v]) dfs(x);
}

char tmp[505][505];

int main(){
	scanf("%d",&n);m = n;
	int rt = New(0);
	FOR(i,1,m) G[rt].pb(New(0));
	FOR(i,1,n){
		scanf("%s",str+1);
		FOR(j,1,m) tmp[i][j] = str[j];
		apply(rt);
		work(rt);
		gao(rt);
	}
	dfs(rt);
	puts("YES");
	FOR(i,1,n){
		for(auto x:ans) putchar(tmp[i][x]);
		puts("");
	}
	return 0;
}