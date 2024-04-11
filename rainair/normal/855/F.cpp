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
const int inf = 1e9;

#define lc ((x)<<1)
#define rc ((x)<<1|1)

struct SGT{

	struct Node{
		int mx,cmx,cnt;LL coe,sm,csm;
	
		inline Node operator + (const Node &t) const {
			Node res;
			if(mx > t.mx){
				res.mx = mx;res.cnt = cnt;
				res.cmx = std::max(cmx,t.mx);
				res.coe = coe;
				res.csm = csm;
			}
			else if(mx == t.mx){
				res.mx = mx;res.cnt = cnt+t.cnt;
				res.cmx = std::max(cmx,t.cmx);
				res.coe = coe+t.coe;
				res.csm = csm+t.csm;
			}
			else{
				res.mx = t.mx;res.cnt = t.cnt;
				res.cmx = std::max(mx,t.cmx);
				res.coe = t.coe;
				res.csm = t.csm;
			}
			res.sm = sm+t.sm;
			return res;
		}
	}sm[MAXN<<2];
	//  min 
	//  mx,cmx,cnt

	inline void build(int x,int l,int r){
		if(l == r){
			sm[x] = (Node){inf,-inf,1,0,0,0};
			return;
		}
		int mid = (l + r) >> 1;
		build(lc,l,mid);build(rc,mid+1,r);
		sm[x] = sm[lc]+sm[rc];
	}

	inline void cover(int x,int d){
		if(sm[x].mx <= d) return;
		if(sm[x].cmx < d){
			sm[x].sm -= sm[x].csm;
			sm[x].csm = sm[x].coe*d;
			sm[x].sm += sm[x].csm;
			sm[x].mx = d;
		}
	}

	inline void pushdown(int x){
		cover(lc,sm[x].mx);
		cover(rc,sm[x].mx);
	}

	inline void modify(int x,int l,int r,int L,int R,int d){
		if(sm[x].mx <= d) return;
		if(l == L && r == R) if(sm[x].cmx < d) return cover(x,d);
		int mid = (l + r) >> 1;pushdown(x);
		if(R <= mid) modify(lc,l,mid,L,R,d);
		else if(L > mid) modify(rc,mid+1,r,L,R,d);
		else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
		sm[x] = sm[lc]+sm[rc];
	}

	inline void update(int x,int l,int r,int p){
		if(l == r){
			sm[x].coe = 1;sm[x].csm = sm[x].sm = sm[x].mx;
			return;
		}
		int mid = (l + r) >> 1;pushdown(x);
		if(p <= mid) update(lc,l,mid,p);
		else update(rc,mid+1,r,p);
		sm[x] = sm[lc]+sm[rc];
	}

	inline Node query(int x,int l,int r,int L,int R){
		if(l == L && r == R) return sm[x];
		int mid = (l + r) >> 1;pushdown(x);
		if(R <= mid) return query(lc,l,mid,L,R);
		if(L > mid) return query(rc,mid+1,r,L,R);
		return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
	}
}t1,t2;

const int n = 1e5;

std::set<int> s0,s1,s2;

int main(){
	t1.build(1,1,n);t2.build(1,1,n);
	int q;scanf("%d",&q);
	FOR(i,1,n) s0.insert(i);
	FOR(i,1,q){
		int o,l,r;scanf("%d%d%d",&o,&l,&r);
		--r;
		if(o == 1){
			int k;scanf("%d",&k);
			if(k > 0){
				t1.modify(1,1,n,l,r,k);
				auto p = s0.lower_bound(l);
				while(p != s0.end() && *p <= r){
					s1.insert(*p);
					p = s0.erase(p);
				}
				p = s2.lower_bound(l);
				while(p != s2.end() && *p <= r){
					t1.update(1,1,n,*p);
					t2.update(1,1,n,*p);
					p = s2.erase(p);
				}
			}
			else{
				k = -k;
				t2.modify(1,1,n,l,r,k);
				auto p = s0.lower_bound(l);
				while(p != s0.end() && *p <= r){
					s2.insert(*p);
					p = s0.erase(p);
				}
				p = s1.lower_bound(l);
				while(p != s1.end() && *p <= r){
					t1.update(1,1,n,*p);
					t2.update(1,1,n,*p);
					p = s1.erase(p);
				}
			}
		}
		else{
			printf("%lld\n",t1.query(1,1,n,l,r).sm+t2.query(1,1,n,l,r).sm);
		}
	}
	return 0;
}