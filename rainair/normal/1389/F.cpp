#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;
std::vector<int> S;

P a[MAXN];int t[MAXN];
std::vector<P> G[MAXN];
int f[MAXN];

struct Seg{
	int mx[MAXN<<2],tag[MAXN<<2];
	#define lc ((x)<<1)
	#define rc ((x)<<1|1)
	
	inline void cover(int x,int d){
		tag[x] += d;mx[x] += d;
	}
	
	inline void pushdown(int x){
		if(tag[x]){
			cover(lc,tag[x]);
			cover(rc,tag[x]);
			tag[x] = 0;
		}
	}
	
	inline void modify(int x,int l,int r,int L,int R,int d){
		if(l == L && r == R){
			cover(x,d);
			return;
		}
		int mid = (l + r) >> 1;pushdown(x);
		if(R <= mid) modify(lc,l,mid,L,R,d);
		else if(L > mid) modify(rc,mid+1,r,L,R,d);
		else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
		mx[x] = std::max(mx[lc],mx[rc]);
	}
	
	inline int query(int x,int l,int r,int L,int R){
		if(l == L && r == R) return mx[x];
		int mid = (l + r) >> 1;pushdown(x);
		if(R <= mid) return query(lc,l,mid,L,R);
		if(L > mid) return query(rc,mid+1,r,L,R);
		return std::max(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
	}
}t1,t2;

int n;

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d%d%d",&a[i].fi,&a[i].se,t+i);
		S.pb(a[i].fi);S.pb(a[i].se);
	}
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n){
		a[i].fi = std::lower_bound(all(S),a[i].fi)-S.begin()+1;
		a[i].se = std::lower_bound(all(S),a[i].se)-S.begin()+1;
		G[a[i].se].pb(MP(a[i].fi,t[i]));
	}
	int m = S.size();
	int ans = 0;
	FOR(i,1,m){
		for(auto x:G[i]){
			if(x.se == 1) t1.modify(1,0,m,0,x.fi-1,1);
			else t2.modify(1,0,m,0,x.fi-1,1);
		}
		f[i] = std::max(t1.query(1,0,m,0,i-1),t2.query(1,0,m,0,i-1));
		t1.modify(1,0,m,i,i,f[i]);t2.modify(1,0,m,i,i,f[i]);
		ans = std::max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
f[i]: i
f[i] = max_j {f[j-1]+w(i,j)}
f[j-1]+w(i,j) 
,

*/