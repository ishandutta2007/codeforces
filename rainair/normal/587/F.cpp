#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
const int MAXM = 1e5 + 5;
int ans[MAXN];LL tmp[MAXM];
int T;
std::vector<int> pos[MAXM],suf[MAXN];// 
struct SAM{
	int fail[MAXN],len[MAXN];
	std::map<char,int> ch[MAXN];
	int tot = 1,las = 1;

	inline void copy(int x,int y){
		// FOR(i,0,25) ch[x][i] = ch[y][i];
		ch[x] = ch[y];
		fail[x] = fail[y];len[x] = len[y];
	}

	inline int split(int p,int c){
		int q = ch[p][c],nq = ++tot;
		copy(nq,q);len[nq] = len[p]+1;
		fail[q] = nq;
		while(p&&ch[p][c] == q) ch[p][c] = nq,p = fail[p];
		return nq;
	}

	inline int insert(int c){
		int p = las,q = ch[p][c];
		if(q){
			if(len[q] == len[p]+1) return q;
			else return split(p,c);
		}
		int np = ++tot;len[np] = len[p]+1;
		while(p&&!ch[p][c]) ch[p][c] = np,p = fail[p];
		if(!p) fail[np] = 1;
		else{
			int q = ch[p][c];
			if(len[q] == len[p]+1) fail[np] = q;
			else fail[np] = split(p,c);
		}
		return np;
 	}

	std::vector<int> G[MAXN];
	int dfn[MAXN],sz[MAXN];
	inline void dfs(int v){
		static int ts = 0;
		dfn[v] = ++ts;sz[v] = 1;
		for(auto x:G[v]){
			dfs(x);
			sz[v] += sz[x];
		}
	}

	inline void build(){
		FOR(i,2,tot) G[fail[i]].pb(i);
		dfs(1);
	}

	inline void dfs1(int v){
		for(auto x:G[v]){
			dfs1(x);
			ans[v] += ans[x];
		}
		for(auto x:suf[v]) tmp[x] += ans[v];
	}
}sam;

struct DS{
	int blo[MAXN];LL tag[MAXN],val[MAXN];
	int BASE;

	inline void init(int n){
		BASE = std::sqrt(1.0*n);BASE = std::max(BASE,1);
		FOR(i,1,n) blo[i] = (i-1)/BASE+1;
	}

	inline void modify(int l,int r,int d){
		if(blo[l] == blo[r]){
			FOR(i,l,r) val[i] += d;
			return;
		}
		FOR(i,l,blo[l]*BASE) val[i] += d;
		FOR(i,blo[l]+1,blo[r]-1) tag[i] += d;
		FOR(i,(blo[r]-1)*BASE+1,r) val[i] += d;
	}

	inline int query(int x){
		return val[x]+tag[blo[x]];
	}
}Tr;

int n,q;
char str[MAXM];

struct Node{
	LL l:19;
	LL r:19;
	LL id:19;
	Node(int l=0,int r=0,int id=0) : l(l),r(r),id(id) {}
};

std::vector<Node> qu[MAXM];
std::vector<Node> qq[MAXM]; // <v,id,+-1>
LL res[MAXM];

int main(){
	scanf("%d%d",&n,&q);
	FOR(i,1,n){
		scanf("%s",str+1);
		sam.las = 1;
		int len = strlen(str+1);
		FOR(j,1,len){
			sam.las = sam.insert(str[j]-'a');
			pos[i].pb(sam.las);
		}
		suf[pos[i][(int)pos[i].size()-1]].pb(i);
		T += len;
	}
	// DEBUG(pos[5][0]);
	sam.build(); 
	T = std::sqrt(1.0*T);
	FOR(i,1,q){
		int l,r,v;scanf("%d%d%d",&l,&r,&v);
		qu[v].pb(Node(l,r,i));
	}
	FOR(i,1,n){
		if(pos[i].size() >= T){
			FOR(i,1,sam.tot) ans[i] = 0;
			FOR(i,1,n) tmp[i] = 0;
			for(auto x:pos[i]) ans[x] = 1;
			sam.dfs1(1);
			// FOR(i,1,n) DEBUG(tmp[i]);
			FOR(i,1,n) tmp[i] += tmp[i-1];
			for(auto x:qu[i]){
				res[x.id] += tmp[x.r]-tmp[x.l-1];
			}
			qu[i].clear();
		}
	}
	FOR(i,1,sam.tot) suf[i].clear();
	FOR(i,1,n){
		if(pos[i].size() < T){
			for(auto x:qu[i]){
				for(auto v:pos[i]){
					qq[x.r].pb(Node(v,(int)x.id,1));
					qq[x.l-1].pb(Node(v,(int)x.id,-1));
				}
			}
			qu[i].clear();
		}
	}
	Tr.init(sam.tot);
	// exit(0);
	FOR(i,1,n){
		int t = pos[i][(int)pos[i].size()-1];
		Tr.modify(sam.dfn[t],sam.dfn[t]+sam.sz[t]-1,1);
		for(auto x:qq[i]) res[(int)x.r] += (int)x.id*Tr.query(sam.dfn[(int)x.l]);
		pos[i].clear();
	}
	FOR(i,1,q) printf("%lld\n",res[i]);
	return 0;
}