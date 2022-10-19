//template update

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal


namespace basics{
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`


int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

/* 
u^v % mod
*/
ll power(ll u,ll v,ll mod){
    ll ret=1,t=u%mod;
    while (v){
        if (v&1) ret=t*ret%mod;
        t=t*t%mod, v>>=1;
    }
    return ret%mod;
}
 
/*
gcd(a,b)ax+by=gcd(a,b)
ret=exgcd(a,b,x,y); 
*/
ll exgcd(ll a,ll b,ll &x,ll &y){
    if (b){
        ll d=exgcd(b,a%b,y,x);
        return y-=a/b*x, d;
    }
    return x=1,y=0,a;
}
 
/*
x=a(mod m), x=b(mod n)-1
ret=crt(a,m,b,n);
*/
ll crt(ll a,ll m,ll b,ll n){
    if (n>m) swap(a,b), swap(n,m);
    ll x,y,g=exgcd(m,n,x,y);
    if ((b-a)%g) return -1;
    x=(b-a)%n*x%n/g*m+a;
    return x<0?x+m*n/g:x;
}
 
/*
<=n
gen_prime<5000>(ret);
*/
 
void gen_prime(int n,vi &ret){
    vector<bool> p;
    p.resize(n+1,1);
    p[0]=p[1]=0;
    for (int i=4;i<=n;i+=2) p[i]=0;
    for (int i=3;i*i<=n;i+=2){
        if (p[i]){
            for (int j=i*i;j<=n;j+=2*i){
                p[j]=0;
            }
        }
    }
    for (int i=2;i<=n;++i){
        if (p[i]) ret.pb(i);
    }
}
 
/*
<=nphi
gen_phi<5000>(ret);
*/
void gen_phi(int n,vi &phi){
    phi.resize(n+1);
    for (int i=0;i<=n;++i) phi[i]=i&1?i:i/2;
    for (int i=3;i<=n;i+=2){
        if (phi[i]==i){
            for (int j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
        }
    }
}
 
/*

expower.mod_pow(a,b,mod);
*/
 
struct expower{
    ull mod_mul(ull a,ull b,ull M) {
        ll ret=a*b-M*ull(ld(a)* ld(b)/ld(M));
        return ret+M*(ret<0)-M*(ret>=(ll)M);
    }
    ull mod_pow(ull b,ull e,ull mod) {
        ull ans=1;
        for (; e; b=mod_mul(b,b,mod), e/=2)
            if (e&1) ans=mod_mul(ans,b,mod);
        return ans%mod;
    }
}expower;
 
/*
Miller-Rubin
is_prime(n);
*/
bool is_prime(ull n){ 
    if (n<2||n%6%4!=1) return n-2<2;
    ull A[]={2,325,9375,28178,450775,9780504,1795265022},
    s=__builtin_ctzll(n-1), d = n >> s;
    for (auto a:A){
        ull p=expower.mod_pow(a,d,n),i=s;
        while (p!=1&&p!=n-1&&a%n&&i--)
            p=expower.mod_mul(p,p,n);
        if (p!=n-1&&i!=s) return 0;
    }
    return 1;
}
 
/*

ret=factorization(n);
*/
ull pollard(ull n){
    auto f=[n](ull x){return (expower.mod_mul(x,x,n)+1)%n;};
    if (!(n&1)) return 2;
    for (ull i=2;;i++){
        ull x=i,y=f(x),p;
        while ((p=__gcd(n+y-x,n))==1)
            x=f(x),y=f(f(y));
        if (p!=n) return p;
    }
}
 
vector<ull> factorization(ull n){
    if (n==1) return {};
    if (is_prime(n)) return {n};
    ull x=pollard(n);
    auto l=factorization(x),r=factorization(n/x);
    l.insert(l.end(),range(r));
    return l;
}
} // namespace basics
 
 /* 
 
 0,1,...,n-1
 */ 
struct DSU{
    //insert info.
    vector<int> p,sz;
    DSU(int n){
        p.resize(n);
        sz.resize(n,1);
        for (int i=1;i<n;++i) p[i]=i;
    }
    int find(int u){
        if (p[u]==u) return u;
        return p[u]=find(find(p[u]));
    } 
    bool unite(int u,int v){
        int pu=find(u), pv=find(v);
        if (pu!=pv){
            p[pu]=pv;
            sz[pv]+=sz[pu];
        }
        return pu!=pv;
    }
};
 
/* (u,v,w) */
template<class T> struct MST{
    vector<tuple<int,int,T> > solve_detail(int n,vector<tuple<int,int,T> >g){
        vector<tuple<int,int,T> > ret;
        ret.clear();
        DSU dsu(n);
        auto cmp=[&](tuple<int,int,T> x,tuple<int,int,T> y){
            int ux,uy,vx,vy;
            T wx,wy;
            tie(ux,vx,wx)=x, tie(uy,vy,wy)=y;
            return wx<wy;
        };
        sort(range(g),cmp);
        for (auto c:g){
            int u,v;
            T w;
            tie(u,v,w)=c;
            if(dsu.unite(u,v)) ret.push_back(c);
        }
        return ret;
    }
    T solve(int n,vector<tuple<int,int,T> > &g){
        auto ret=solve_detail(n,g);
        T res=0;
        for (auto c:ret){
            int a,b;
            T d;
            tie(a,b,d)=c;
            res+=d;
        }
        return res;
    }
};
 
/*
copy from Atcoder library:
    construct: lazy_segtree<S,op,e,F,mapping,composition,id>
    usage: apply(l,r,f), max_left/right(l,g), set(p,x), get(p), prod(l,r) (inclusive,exclusive)
*/
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(sz(v)) {
        log = basics::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

 
struct XORBasis{
    int n;
    vector<ull> p,val;
    vector<ull> ans;
    XORBasis(int k):n(k){
        p.resize(k+1);
        val.resize(k+1);
    }
    void rebuilt(){
        ans.clear();
        for (int i=0;i<=n;++i){
            if (p[i]) ans.push_back(p[i]);
        }
    }
    void insert(ull u,int x){
        for (int i=n;i>=0;--i){
            if (u&(1ull<<i)){
                if (p[i]) u^=p[i], x^=val[i];
                else{
                    p[i]=u, val[i]=x;
                    for (int j=i-1;j>=0;--j){
                        if (p[i]&(1ull<<j)) p[i]^=p[j], val[i]^=val[j];
                    }
                    for (int j=i+1;j<=n;++j){
                        if (p[j]&(1ull<<i)) p[j]^=p[i], val[j]^=val[i];
                    }
                    break;
                }
            }
        }
        rebuilt();
    }
    bool check(ull u){
        for (int i=n;i>-1;--i){
            if (u&(1ull<<i)) u^=p[i];
        }
        return (u==0);
    }
    ull kth(ull t){ // the k-th smallest, excluding 0.
        if (t>=(1ull<<sz(ans))) return -1;
        ull ret=0;
        for (int i=0;i<sz(ans);++i){
            if (t&(1ull<<i)) ret^=ans[i];
        }
        return ret;
    }
    ull total(){
        return (1ull<<sz(ans));
    }
};
 
/* 
pi: gen vector pi for string s
match: find out all possible matches for pattern pat
*/

struct KMP{ 
    vi pi(const string& s) {
	    vi p(sz(s));
	    for (int i=1;i<=sz(s);++i) {
	    	int g = p[i-1];
	    	while (g && s[i] != s[g]) g = p[g-1];
	    	p[i] = g + (s[i] == s[g]);
    	}
	    return p;
    }
    
    vi match(const string& s, const string& pat) {
	    vi p = pi(pat + '\0' + s), res;
	    for(int i=sz(p)-sz(s);i<=sz(p);++i)
	    	if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	    return res;
    }
};
 
struct AhoCorasick {
	enum {alpha = 26, first = 'a'};
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1;
        ll nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vector<int> backp;
	void insert(string& s, int j,ll val) {
		assert(!s.empty());
		int n = 0;
		for(auto c:s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches+=val;
	}
	AhoCorasick(vector<string>& pat,vi val) {
		N.emplace_back(-1);
		for (int i=0;i<sz(pat);++i) insert(pat[i], i, val[i]);
		N[0].back = sz(N);
		N.emplace_back(0);
 
		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			for (int i=0;i<alpha;++i) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vi find(string& word,ll& ans) {
		int n = 0;
		vi res;
		for(auto c:word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			ans += N[n].nmatches;
		}
		return res;
	}
	vector<vi> findAll(vector<string>& pat, string word) {
		ll ans=0;
        vi r = find(word,ans);
		vector<vi> res(sz(word));
		for (int i=0;i<sz(word);++i) {
			int ind = r[i];
			while (ind != -1) {
				res[i - sz(pat[ind]) + 1].push_back(ind);
				ind = backp[ind];
			}
		}
		return res;
	}
};
 
struct HLD{
    int n,cnt=0;
    vector<vi> G;
    vi par,dep,siz,son,top,dfn,rk; 
    //dfsdfs
    HLD(vector<vi> g,int root=1):n(sz(g)),G(g),par(n+7),dep(n+7),siz(n+7,1),son(n+7,-1),top(n+7),dfn(n+7),rk(n+7){
        dep[0]=-1, dfs1(root,0), dfs2(root,0,root);
    }
    void dfs1(int u,int p){
        for (auto c:G[u]){
            if (c==p) continue;
            dep[c]=dep[u]+1, par[c]=u;
            dfs1(c,u);
            siz[u]+=siz[c];
            if (son[u]==-1||siz[son[u]]<siz[c]) son[u]=c;
        }
    }
    void dfs2(int u,int p,int tp){
        top[u]=tp;
        dfn[u]=++cnt;
        rk[cnt]=u;
        if (son[u]==-1) return;
        dfs2(son[u],u,tp);
        for (auto c:G[u]){
            if (c==p||c==son[u]) continue;
            dfs2(c,u,c);
        }
    }
    int lca(int u,int v){
        while (top[u]!=top[v]){
            if (dep[top[u]]>dep[top[v]]){
                u=par[top[u]];
            }
            else{
                v=par[top[v]];
            }
        }
        return dep[u]>dep[v]?v:u;
    }
    vector<pii> find_seg(int u,int v){
        vector<pii> ft,bk,res;
        ft.clear(), bk.clear(), res.clear();
//        cout<<top[u]<<" "<<top[v]<<endl;
        while (top[u]!=top[v]){
            if (dep[top[u]]>dep[top[v]]){
                ft.pb({u,top[u]});
                u=par[top[u]];
            }
            else{
                bk.pb({top[v],v});
                v=par[top[v]];
            }
        }
        ft.pb({u,v});
        for (int i=0;i<sz(ft);++i) res.pb(ft[i]);
        for (int i=sz(bk);i>0;--i) res.pb(bk[i-1]);
        return res;
    }
};
 
struct BIT{
    vi C; int n;
    BIT(int n):n(n){C.resize(n+7,0);}
    void update(int u,int w){
        for (;u<=n;u+=u&(-u)) C[u]+=w;
    }
    int query(int u){
        int res=0;
        for (;u>0;u-=u&(-u)) res+=C[u];
        return res; 
    }
};

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority queue for lexic. smallest ans.
	rep(i,sz(gr)) if (indeg[i] == 0) q.push(-i);
	while (!q.empty()) {
		int i = -q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(-x);
	}
	return ret;
}

struct Eulerian{
  public:
    Eulerian(int n,int m):_n(n),_m(m){
        path.clear();
        _g.resize(n,vector<pii>(0));
        pt.resize(n,0);
        vis.resize(m,0);
        deg.resize(n,0);    
    }
    void add(int x,int y,int id){
        _g[x].pb({y,id});
        pt[x]++;
        nxt=x;
        deg[y]++;
    }
    bool solve(){
        rep(i,_n) if (deg[i]&1) return false;
        dfs(nxt);
        if (sz(path)<_m) return 0;
        return true;
    }
    vi solve_path(){
        if (!solve()) path.clear();
        reverse(range(path));
        return path;
    }
  private:
    int _n,_m,nxt;
    vi path;
    vector<vector<pii>> _g;
    vi pt;
    vi deg;
    vector<bool> vis;
    int abs(int u){
        if (u<0) return ~u;
        return u;
    }
    void dfs(int u){
        while (pt[u]){
            while (pt[u]&&vis[abs(_g[u][pt[u]-1].S)]) pt[u]--;
            if (!pt[u]) break;
            int to=_g[u][pt[u]-1].F, id=_g[u][pt[u]-1].S;
            vis[abs(id)]=1;
            dfs(to), path.pb(id);
        }
    }
};

template<class T> struct FWT{
  public:
    vector<T> OR(vector<T> &a){
        return _OR(a,1);
    }
    vector<T> ROR(vector<T> &a){
        return _OR(a,-1);
    }
    vector<T> AND(vector<T> &a){
        return _AND(a,1);
    }
    vector<T> RAND(vector<T> &a){
        return _AND(a,-1);
    }
    vector<T> XOR(vector<T> &a){
        return _XOR(a,1);
    }
    vector<T> RXOR(vector<T> &a){
        return _XOR(a,-1);
    }
  private:
    vector<T> _OR(vector<T> &a,int mode=1){
        vector<T> b(a);
        for (int i=0;(1<<i)<sz(a);++i){
            for (int j=0;j<sz(a);++j){
                if (j>>i&1) b[j]+=b[j^(1<<i)]*mode; 
            }
        }
        return b;
    }
    vector<T> _AND(vector<T> &a,int mode=1){
        vector<T> b(a);
        for (int i=0;(1<<i)<sz(a);++i){
            for (int j=0;j<sz(a);++j){
                if (j>>i&1) b[j^(1<<i)]+=b[j]*mode;
            }
        }
        return b;
    }
    vector<T> _XOR(vector<T> &a,int mode=1){
        vector<T> b(a);
        for (int i=0;(1<<i)<sz(a);++i){
            for (int j=0;j<sz(a);++j){
                if (j>>i&1){
                    b[j^(1<<i)]+=b[j];
                    b[j]=b[j^(1<<i)]-2*b[j];
                    if (mode<0) b[j]/=2, b[j^(1<<i)]/=2;
                }
            }
        }
        return b;
    }
};

/* atcoder mincost-maxflow */
template <class Cap, class Cost> struct mcf_graph {
  public:
    mcf_graph() {}
    explicit mcf_graph(int n) : _n(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = (int)_edges.size();
        _edges.push_back({from, to, cap, 0, cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = (int)_edges.size();
        assert(0 <= i && i < m);
        return _edges[i];
    }
    std::vector<edge> edges() { return _edges; }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        int m = _edges.size();
        std::vector<int> edge_idx(m);

        auto g = [&]() {
            std::vector<int> degree(_n), redge_idx(m);
            std::vector<std::pair<int, _edge>> elist;
            elist.reserve(2 * m);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] = degree[e.from]++;
                redge_idx[i] = degree[e.to]++;
                elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
                elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
            }
            auto _g = internal::csr<_edge>(_n, elist);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] += _g.start[e.from];
                redge_idx[i] += _g.start[e.to];
                _g.elist[edge_idx[i]].rev = redge_idx[i];
                _g.elist[redge_idx[i]].rev = edge_idx[i];
            }
            return _g;
        }();

        auto result = slope(g, s, t, flow_limit);

        for (int i = 0; i < m; i++) {
            auto e = g.elist[edge_idx[i]];
            _edges[i].flow = _edges[i].cap - e.cap;
        }

        return result;
    }

  private:
    int _n;
    std::vector<edge> _edges;

    // inside edge
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge>& g,
                                            int s,
                                            int t,
                                            Cap flow_limit) {
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge

        // dual_dist[i] = (dual[i], dist[i])
        std::vector<std::pair<Cost, Cost>> dual_dist(_n);
        std::vector<int> prev_e(_n);
        std::vector<bool> vis(_n);
        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        std::vector<int> que_min;
        std::vector<Q> que;
        auto dual_ref = [&]() {
            for (int i = 0; i < _n; i++) {
                dual_dist[i].second = std::numeric_limits<Cost>::max();
            }
            std::fill(vis.begin(), vis.end(), false);
            que_min.clear();
            que.clear();

            // que[0..heap_r) was heapified
            size_t heap_r = 0;

            dual_dist[s].second = 0;
            que_min.push_back(s);
            while (!que_min.empty() || !que.empty()) {
                int v;
                if (!que_min.empty()) {
                    v = que_min.back();
                    que_min.pop_back();
                } else {
                    while (heap_r < que.size()) {
                        heap_r++;
                        std::push_heap(que.begin(), que.begin() + heap_r);
                    }
                    v = que.front().to;
                    std::pop_heap(que.begin(), que.end());
                    que.pop_back();
                    heap_r--;
                }
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                // dist[v] = shortest(s, v) + dual[s] - dual[v]
                // dist[v] >= 0 (all reduced cost are positive)
                // dist[v] <= (n-1)C
                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto e = g.elist[i];
                    if (!e.cap) continue;
                    // |-dual[e.to] + dual[v]| <= (n-1)C
                    // cost <= C - -(n-1)C + 0 = nC
                    Cost cost = e.cost - dual_dist[e.to].first + dual_v;
                    if (dual_dist[e.to].second - dist_v > cost) {
                        Cost dist_to = dist_v + cost;
                        dual_dist[e.to].second = dist_to;
                        prev_e[e.to] = e.rev;
                        if (dist_to == dist_v) {
                            que_min.push_back(e.to);
                        } else {
                            que.push_back(Q{dist_to, e.to});
                        }
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                // dual[v] = dual[v] - dist[t] + dist[v]
                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
                //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,
                //         t) + dual[t] + shortest(s, v) = shortest(s, v) -
                //         shortest(s, t) >= 0 - (n-1)C
                dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
            }
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                auto& e = g.elist[prev_e[v]];
                e.cap += c;
                g.elist[e.rev].cap -= c;
            }
            Cost d = -dual_dist[s].first;
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }
};

template<class G, void (*f)(vi&)>  struct SCC{
    vi val, comp, z, cont;
    int Time, ncomps;
    int dfs(int j, G& g) {
	    int low = val[j] = ++Time, x; z.push_back(j);
	    for (auto [e,w] : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g));

	    if (low == val[j]) {
		    do {
			    x = z.back(); z.pop_back();
			    comp[x] = ncomps;
			    cont.push_back(x);
		    } while (x != j);
            f(cont), cont.clear();
		    ncomps++;
	    }
	    return val[j] = low;
    }
    void scc(G& g) {
	    int n = sz(g);
	    val.assign(n, 0); comp.assign(n, -1);
	    Time = ncomps = 0;
	    rep(i,n) if (comp[i] < 0) dfs(i, g);
    }
};

const int maxn=100007;

const int mod=1e9+7;

int t;
int n,k,f[maxn],rf[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    f[0]=rf[0]=1;
    rep1(i,100000) f[i]=f[i-1]*i%mod, rf[i]=basics::power(f[i],mod-2,mod);
    auto C=[&](int u,int v){
        return f[u]*(rf[v]*rf[u-v]%mod)%mod;
    };
    while (t--){
        cin>>n>>k;
        int res=0,prv=f[n];
        rep1(i,n){
            int cnt;
            if (n<(i-1)*k) cnt=0;
            else cnt=(C(n-(i-1)*(k-1),i)*f[n-i]%mod)*f[i]%mod;
//            cout<<i<<" "<<cnt<<endl;
            res+=i*(prv-cnt+mod)%mod;
            res%=mod;
            prv=cnt;
        }
        cout<<res*rf[n]%mod<<"\n";
    }

    return 0;
}

/*
3
3 2 1
2 3 2
1 1 3
*/